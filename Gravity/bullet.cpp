#include "stdafx.h"
#include "bullet.h"
#include <GL/freeglut.h>
#include <math.h>

#define Gravity 10
#define PI 3.1415
#define DOUBLE(X) ((X)*(X))

Bullet::Bullet() 
{
	
}
void Bullet::Render(float *BulletX,float *BulletY) 
{

}
void Bullet::Move(float angle,float *BulletX,float *BulletY,float Power,float DeltaT)//��ź ������ 
{
	float Radian = angle*PI / 180;
	BulletX += (int)(Power*cosf(Radian)*DeltaT);
	BulletY += (int)((Power*sinf(Radian)*DeltaT) - (Gravity*DOUBLE(DeltaT))/2); 
	//bullet ��ġ==�� �����Ӹ��� ���ؼ� ���ϱ�
}                                       //��ź ��ġ:�� �����Ӹ��� ������ �Ÿ� �����ؼ� ��ź ��ġ�� �ѱ�
Bullet::~Bullet()    //bullet ���� �� �������� ��
{
	
}
