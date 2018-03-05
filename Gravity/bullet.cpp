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
void Bullet::Move(float angle,float *BulletX,float *BulletY,float Power,float DeltaT)//포탄 움직임 
{
	float Radian = angle*PI / 180;
	BulletX += (int)(Power*cosf(Radian)*DeltaT);
	BulletY += (int)((Power*sinf(Radian)*DeltaT) - (Gravity*DOUBLE(DeltaT))/2); 
	//bullet 위치==매 프레임마다 더해서 구하기
}                                       //포탄 위치:매 프레임마다 움직인 거리 적분해서 포탄 위치로 넘김
Bullet::~Bullet()    //bullet 폭파 시 렌더링할 것
{
	
}
