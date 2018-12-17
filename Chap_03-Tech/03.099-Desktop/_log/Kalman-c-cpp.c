//Function: calculate the variance of a group of data
//pData---> List of Data
//num-----> length of the data array
//fVariance----> The Variance of the data list
void Deviation(const float *pData, const int num, float &fVariance)
{
    int i;
    float fMEAN,fSUM = 0.0,fSUM2 = 0.0;
    for (i = 0; i < num; i ++)
    {
        fSUM += pData[i];
    }
    fMEAN = fSUM/num;
    for (i = 0; i < num; i ++)
    {
        fSUM2 += (pData[i] - fMEAN)*(pData[i] - fMEAN);
    }
    fVariance = fSUM2/num;
}
 
 
//Input - vData. Data array in the format of QStringList(1-D Array) 
//Output - fKalmanResult. The result of kalman filtering, 
//         i.e., the weighted average.
//         fPSNR- Peak Signal to Noise Ratio
void KalmanFilter(QStringList &vData, float &fKalmanResult, float &fPSNR)
{
    // Load Data
    double  D_RAND_MAX = 32767.0;
    int nSize = vData.size();
    if (nSize == 0)
    {
        return ;
    }
    int i;
    float *pfW = new float[nSize], *pfV = new float[nSize];
    float *pfX = new float[nSize], *pfY = new float[nSize];
    for (i = 0; i < nSize; i ++)
    {
        pfW[i] = 0.1*(double)rand()/D_RAND_MAX -0.05;
        pfV[i] = (double)rand()/D_RAND_MAX - 0.5;
    }
    float Rvv,Rxx,Qww;
    Deviation(pfV,nSize,Rvv);
    Deviation(pfW,nSize,Qww);
    for (i = 0; i < nSize; i ++)
    {
        pfY[i] = vData[i].trimmed().toDouble(); 
    }
 
    //Filter
    float *pfP = new float[nSize], *pfBs = new float[nSize];
    float *pfP1 = new float[nSize], *pfKg = new float[nSize];
    float fTemp = 0.0;
    pfX[0] = 0.0,pfP[0] = 1.0,pfBs[0] = 0.0;
    for (i = 1; i < nSize; i++)
    {
        pfX[i] = pfBs[i-1];
        pfP1[i] = pfP[i-1] + 0.0025;
        pfKg[i] = pfP1[i]/(pfP1[i] + 0.25);
        pfBs[i] = pfX[i] + pfKg[i]*(pfY[i] - pfX[i]);
        pfP[i] = pfP1[i] - pfKg[i]*pfP1[i];
        fTemp += pfBs[i];
    }
    //实际的Kalman滤波至此即结束，pfBs为最优估计，pfX为基于上一时刻的估计，pfY为观测值
    //As for the array with only a numerical data
    if (nSize == 1)
    {
        pfBs[0] = pfY[0];
        fKalmanResult = pfBs[nSize-1];
    }
    else
    {
        fKalmanResult = fTemp/(float)(nSize-1);    
    }
    
    delete []pfW; delete []pfV;
    delete []pfX; delete []pfY;
    delete []pfP; delete []pfBs;
    delete []pfP1; delete []pfKg;
 
    // calculate the PSNR
    float mse = 0.0;
    float maxData = 0.0;
    for (i = 0; i < vData.size(); i ++)
    {
        // Search the max data
        float f_data = vData[i].trimmed().toFloat();
        if (f_data > maxData)
            maxData = f_data;
        // calculate the mse: step1
        mse += (f_data-fKalmanResult)*(f_data-fKalmanResult);
    }
    //step2
    mse = mse / (float)(vData.size());
    if (mse > 0)
    {
        fPSNR = 10.0 * (float)log10(maxData*maxData/mse);
    }
    else
        fPSNR = 0.0;
}
 
 
//===================================================//
// 一维滤波器信息结构体
typedef  struct{
    double X;   // k-1时刻的滤波值，即是k-1时刻的值
    double P;   // 估计误差协方差
    double K;   // Kalamn增益
    double A;   // x(n)=A*x(n-1)+u(n), u(n)~N(0,Q)
    double H;   // z(n)=H*x(n)+w(n),   w(n)~N(0,R)
    double Q;   // 过程噪声偏差的方差
    double R;   // 测量噪声偏差，(系统搭建好以后，通过测量统计实验获得)
}  kalmanType;
/**
* @brief Init_k   初始化滤波器的初始值
* @param init  滤波器指针
* @param Q 预测噪声方差 由系统外部测定给定
* @param R 测量噪声方差 由系统外部测定给定
*/
void Init_k(kalmanType* init, double Q, double R)
{
    init->X = 0;    //测量的初始值
    init->P = 10;   //后验状态估计值误差的方差的初始值（不要为0问题不大）
    init->A = 1;    //转换系数
    init->H = 1;    //观测系数
    init->Q = Q;    //预测（过程）噪声方差 影响收敛速率，可以根据实际需求给出
    init->R = R;    //测量（观测）噪声方差 可以通过实验手段获得
}
double KalmanFilter(kalmanType* k, double measureValue)
{
    //1-预测下一时刻的值
    double predictValue = (k->A) * (k->X);    //x的先验估计由上一个时间点的后验估计值和输入信息给出，此处需要根据基站高度做一个修改
    //2-求协方差
    k->P = (k->A) * (k->A) * (k->P) + (k->Q); //计算先验均方差 p(n|n-1)=A^2*p(n-1|n-1)+q
    double preValue = k->X;                   //记录上次实际坐标的值
    //3-计算kalman增益
    k->K = (k->P) * (k->H) / ((k->P) * (k->H) * (k->H) + (k->R)); //Kg(k)= P(k|k-1) H’ / (H P(k|k-1) H’ + R)
    //4-修正结果，即计算滤波值
    //5-更新后验估计
    // 利用残余的信息改善对x(t)的估计，给出后验估计，这个值也就是输出  X(k|k)= X(k|k-1)+Kg(k) (Z(k)-H X(k|k-1))
    k->X = predictValue + (measureValue - ((k->H) * predictValue)) * (k->K);  
    k->P = (1 - (k->K) * (k->H)) * (k->P);    //计算后验均方差  P[n|n]=(1-K[n]*H)*P[n|n-1]
 
    return  k->X;
}







/*
 * FileName : kalman_filter.h
 * Author   :Ethan_Lei_Pro
 * Version  : v1.0
 * Date     : 2017/5/10 10:37:01
 * Brief    : 
 * 
 * Copyright (C) MICL,USTB
 */
#ifndef  _KALMAN_FILTER_H
#define  _KALMAN_FILTER_H
 
/* 
 * NOTES: n Dimension means the state is n dimension, 
 * measurement always 1 dimension 
 */
 
/* 1 Dimension */
typedef struct {
    float x;  /* state */
    float A;  /* x(n)=A*x(n-1)+u(n),u(n)~N(0,q) */
    float H;  /* z(n)=H*x(n)+w(n),w(n)~N(0,r)   */
    float q;  /* process(predict) noise convariance */
    float r;  /* measure noise convariance */
    float p;  /* estimated error convariance */
    float gain;
} kalman1_state;
 
/* 2 Dimension */
typedef struct {
    float x[2];     /* state: [0]-angle [1]-diffrence of angle, 2x1 */
    float A[2][2];  /* X(n)=A*X(n-1)+U(n),U(n)~N(0,q), 2x2 */
    float H[2];     /* Z(n)=H*X(n)+W(n),W(n)~N(0,r), 1x2   */
    float q[2];     /* process(predict) noise convariance,2x1 [q0,0; 0,q1] */
    float r;        /* measure noise convariance */
    float p[2][2];  /* estimated error convariance,2x2 [p0 p1; p2 p3] */
    float gain[2];  /* 2x1 */
} kalman2_state;                   
 
extern void kalman1_init(kalman1_state *state, float init_x, float init_p);
extern float kalman1_filter(kalman1_state *state, float z_measure);
extern void kalman2_init(kalman2_state *state, float *init_x, float (*init_p)[2]);
extern float kalman2_filter(kalman2_state *state, float z_measure);
 
#endif  /*_KALMAN_FILTER_H*/


#include "kalman_filter.h"
 /*
 * @brief   
 *   Init fields of structure @kalman1_state.
 *   I make some defaults in this init function:
 *     A = 1;
 *     H = 1; 
 *   and @q,@r are valued after prior tests.
 *
 *   NOTES: Please change A,H,q,r according to your application.
 *
 * @inputs  
 *   state - Klaman filter structure
 *   init_x - initial x state value   
 *   init_p - initial estimated error convariance
 * @outputs 
 * @retval  
 */
void kalman1_init(kalman1_state *state, float init_x, float init_p)
{
    state->x = init_x;
    state->p = init_p;
    state->A = 1;
    state->H = 1;
    state->q = 2e2;//10e-6;  /* predict noise convariance */
    state->r = 5e2;//10e-5;  /* measure error convariance */
}
 
/*
 * @brief   
 *   1 Dimension Kalman filter
 * @inputs  
 *   state - Klaman filter structure
 *   z_measure - Measure value
 * @outputs 
 * @retval  
 *   Estimated result
 */
float kalman1_filter(kalman1_state *state, float z_measure)
{
    /* Predict */
    state->x = state->A * state->x;
    state->p = state->A * state->A * state->p + state->q;  /* p(n|n-1)=A^2*p(n-1|n-1)+q */
 
    /* Measurement */
    state->gain = state->p * state->H / (state->p * state->H * state->H + state->r);
    state->x = state->x + state->gain * (z_measure - state->H * state->x);
    state->p = (1 - state->gain * state->H) * state->p;
 
    return state->x;
}
 
/*
 * @brief   
 *   Init fields of structure @kalman1_state.
 *   I make some defaults in this init function:
 *     A = {{1, 0.1}, {0, 1}};
 *     H = {1,0}; 
 *   and @q,@r are valued after prior tests. 
 *
 *   NOTES: Please change A,H,q,r according to your application.
 *
 * @inputs  
 * @outputs 
 * @retval  
 */
void kalman2_init(kalman2_state *state, float *init_x, float (*init_p)[2])
{
    state->x[0]    = init_x[0];
    state->x[1]    = init_x[1];
    state->p[0][0] = init_p[0][0];
    state->p[0][1] = init_p[0][1];
    state->p[1][0] = init_p[1][0];
    state->p[1][1] = init_p[1][1];
    //state->A       = {{1, 0.1}, {0, 1}};
    state->A[0][0] = 1;
    state->A[0][1] = 0.1;
    state->A[1][0] = 0;
    state->A[1][1] = 1;
    //state->H       = {1,0};
    state->H[0]    = 1;
    state->H[1]    = 0;
    //state->q       = {{10e-6,0}, {0,10e-6}};  /* measure noise convariance */
    state->q[0]    = 10e-7;
    state->q[1]    = 10e-7;
    state->r       = 10e-7;  /* estimated error convariance */
}
 
/*
 * @brief   
 *   2 Dimension kalman filter
 * @inputs  
 *   state - Klaman filter structure
 *   z_measure - Measure value
 * @outputs 
 *   state->x[0] - Updated state value, Such as angle,velocity
 *   state->x[1] - Updated state value, Such as diffrence angle, acceleration
 *   state->p    - Updated estimated error convatiance matrix
 * @retval  
 *   Return value is equals to state->x[0], so maybe angle or velocity.
 */
float kalman2_filter(kalman2_state *state, float z_measure)
{
    float temp0 = 0.0f;
    float temp1 = 0.0f;
    float temp = 0.0f;
 
    /* Step1: Predict */
    state->x[0] = state->A[0][0] * state->x[0] + state->A[0][1] * state->x[1];
    state->x[1] = state->A[1][0] * state->x[0] + state->A[1][1] * state->x[1];
    /* p(n|n-1)=A^2*p(n-1|n-1)+q */
    state->p[0][0] = state->A[0][0] * state->p[0][0] + state->A[0][1] * state->p[1][0] + state->q[0];
    state->p[0][1] = state->A[0][0] * state->p[0][1] + state->A[1][1] * state->p[1][1];
    state->p[1][0] = state->A[1][0] * state->p[0][0] + state->A[0][1] * state->p[1][0];
    state->p[1][1] = state->A[1][0] * state->p[0][1] + state->A[1][1] * state->p[1][1] + state->q[1];
 
    /* Step2: Measurement */
    /* gain = p * H^T * [r + H * p * H^T]^(-1), H^T means transpose. */
    temp0 = state->p[0][0] * state->H[0] + state->p[0][1] * state->H[1];
    temp1 = state->p[1][0] * state->H[0] + state->p[1][1] * state->H[1];
    temp  = state->r + state->H[0] * temp0 + state->H[1] * temp1;
    state->gain[0] = temp0 / temp;
    state->gain[1] = temp1 / temp;
    /* x(n|n) = x(n|n-1) + gain(n) * [z_measure - H(n)*x(n|n-1)]*/
    temp = state->H[0] * state->x[0] + state->H[1] * state->x[1];
    state->x[0] = state->x[0] + state->gain[0] * (z_measure - temp); 
    state->x[1] = state->x[1] + state->gain[1] * (z_measure - temp);
 
    /* Update @p: p(n|n) = [I - gain * H] * p(n|n-1) */
    state->p[0][0] = (1 - state->gain[0] * state->H[0]) * state->p[0][0];
    state->p[0][1] = (1 - state->gain[0] * state->H[1]) * state->p[0][1];
    state->p[1][0] = (1 - state->gain[1] * state->H[0]) * state->p[1][0];
    state->p[1][1] = (1 - state->gain[1] * state->H[1]) * state->p[1][1];
 
    return state->x[0];
}



