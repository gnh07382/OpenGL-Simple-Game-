#pragma once
#ifndef __BULLET_H__
#define __BULLET_H__

#define MAX_BULLET 4

class Bullet 
{
public:
	Bullet();
	~Bullet();

	void Render(float *BulletX,float *BulletY);
	void Move(float angle, float *BulletX, float *BulletY, float Power,float DeltaT);

private:
	float BulletXSize;
	float BulletYSize;
	int BulletType;

};


#endif // !__BULLET_H__
