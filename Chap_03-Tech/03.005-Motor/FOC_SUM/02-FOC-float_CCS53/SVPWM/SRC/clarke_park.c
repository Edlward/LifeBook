//***************************************************/
//文件名：clarke_park.c
//功能：克拉克变换和帕克变化子函数
//说明：输入信息采用结构体，使用时改变结构体指针即可改变输入量
//     函数park（）实现帕克变化
//     函数clarke（）实现克拉克变化
//     最终将采样的电流信号转换为两项旋转坐标下信号
//****************************************************/

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File
#include "math.h"
#include "float.h"

#define PI 3.1415926

typedef struct
{
   float as;                // 三项静止坐标轴系下信号
   float bs;           
   float alpha;             // 两项静止坐标系下信号
   float beta;
}CLARKE;
CLARKE CLARKE1={0,0,0,0};

typedef struct
{
   float alpha;           // 两静止平面坐标系下电压信号
   float beta;
   float ang;             // 电气角度 电气角度=机械角度*极对数
   float de;              // 旋转坐标系下电压信号
   float qe;
}PARK;
PARK park1={0,0,0,0,0};

void clarke(CLARKE *v)
{
	v->alpha = v->as;
	v->beta  = (v->as + 2 * v->bs) * (0.57735026918963);    // 1/sqrt(3) = 0.57735026918963
}

void park(PARK *v)
{
	float  ang;
	ang   = (v->ang/360) * 2 * PI;                          //角度转化为弧度
	v->de = v->alpha * cos(ang) + v->beta  * sin(ang);      //得到静止平面坐标系下d轴电压
	v->qe = v->beta  * cos(ang) - v->alpha * sin(ang);      //得到静止平面坐标系下q轴电压
}

