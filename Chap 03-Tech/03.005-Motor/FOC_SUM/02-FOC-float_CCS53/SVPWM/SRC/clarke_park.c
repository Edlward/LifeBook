//***************************************************/
//�ļ�����clarke_park.c
//���ܣ������˱任�����˱仯�Ӻ���
//˵����������Ϣ���ýṹ�壬ʹ��ʱ�ı�ṹ��ָ�뼴�ɸı�������
//     ����park����ʵ�����˱仯
//     ����clarke����ʵ�ֿ����˱仯
//     ���ս������ĵ����ź�ת��Ϊ������ת�������ź�
//****************************************************/

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File
#include "math.h"
#include "float.h"

#define PI 3.1415926

typedef struct
{
   float as;                // ���ֹ������ϵ���ź�
   float bs;           
   float alpha;             // ���ֹ����ϵ���ź�
   float beta;
}CLARKE;
CLARKE CLARKE1={0,0,0,0};

typedef struct
{
   float alpha;           // ����ֹƽ������ϵ�µ�ѹ�ź�
   float beta;
   float ang;             // �����Ƕ� �����Ƕ�=��е�Ƕ�*������
   float de;              // ��ת����ϵ�µ�ѹ�ź�
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
	ang   = (v->ang/360) * 2 * PI;                          //�Ƕ�ת��Ϊ����
	v->de = v->alpha * cos(ang) + v->beta  * sin(ang);      //�õ���ֹƽ������ϵ��d���ѹ
	v->qe = v->beta  * cos(ang) - v->alpha * sin(ang);      //�õ���ֹƽ������ϵ��q���ѹ
}

