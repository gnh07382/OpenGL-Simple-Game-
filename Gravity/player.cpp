#include "player.h"
#include <GL/freeglut.h>
#include <time.h>
#include "bullet.h"

/*
����: glut ���� ���鼭 �߻� �ȵ� �迭 ������ ���ǹ� üũ�ؼ� �߻��ϰ� 
�߻��ϸ� glut���� ���鼭 ���ǹ� Ȯ���ϸ鼭 ��� ���ư��ٰ�
�΋H���� bool ���� ����� �迭 �� ��ź�� �Ҵ�
*/
#define BULLET_MAX 4
#define BulletVelocity 0.00001        //1������ �Ŀ������ӵ� 0.00001 3�� ������ �����ϸ� 0.02  

Player::Player()
{

	dead = false;
	life = 3;
	for (int i = 0; i <BULLET_MAX; i++)
	{
		Bullet_Loaded[i] = true;
		Bullet_Flying[i] = false;
		Bullet_Crashed[i] = false;
		bullet0[i].angle = 30;
		bullet0[i].BulletX = Player_XPos;
		bullet0[i].BulletY = Player_YPos;
		bullet0[i].Power = 0;
	}
}
void Player::render() 
{
	
}
void Player::upgun() 
{
	if (Bullet_Loaded[0]== true) 
	{
		bullet0[0].angle += 0.2;
	}
	else if (Bullet_Loaded[1] == true)
	{
		bullet0[1].angle += 0.2;
	}
	else if (Bullet_Loaded[2] == true)
	{
		bullet0[2].angle += 0.2;
	}
	else if (Bullet_Loaded[3] == true)
	{
		bullet0[3].angle += 0.2;
	}
	else
	{

	}
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (Bullet_Loaded[i]==true && bullet0[i].angle >= 75)
		{
			bullet0[i].angle = 75;
		}
	}//���� �Ѱ�
}
void Player::downgun() 
{
	if (Bullet_Loaded[0] == true)
	{
		bullet0[0].angle -= 0.2;
	}
	else if (Bullet_Loaded[1] == true)
	{
		bullet0[1].angle -= 0.2;
	}
	else if (Bullet_Loaded[2] == true)
	{
		bullet0[2].angle -= 0.2;
	}
	else if (Bullet_Loaded[3] == true)
	{
		bullet0[3].angle -= 0.2;
	}
	else
	{

	}
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (Bullet_Loaded[i]==true && bullet0[i].angle <= 5)
		{
			bullet0[i].angle = 5;
		}
	}                                          //���� �Ѱ�
}
void Player::PowerUpDown()           //60�������̴ϱ� 1�ʿ� 60�� �þ�Ƿ� ��ȯ�ʿ� 
{
	if (Bullet_Loaded[0]==true)
	{
		bullet0[0].Power += BulletVelocity;
	}
	else if (Bullet_Loaded[1] == true) 
	{
		bullet0[1].Power += BulletVelocity;
	}
	else if (Bullet_Loaded[2] == true)
	{

		bullet0[2].Power += BulletVelocity;
	}
	else if (Bullet_Loaded[3] == true)
	{

		bullet0[0].Power += BulletVelocity;
	}
	else
	{
	
	}
}
void Player::fire() //�߻綧 �������� �� �����ְ� �� �ٲٱ� 
{
	for (int i = 0; i < BULLET_MAX; i++) 
	{
		if (Bullet_Loaded[i]==true)             //�̺κ� ��������->����Ű ������ �ð����� �ʿ�->����:�ѹ��� �� �߻��
		{
			Bullet_Loaded[i] = false;
			Bullet_Flying[i] = true;
		}
	}
}
void Player::bullet(float DeltaTime) //bulletmove
{
	Bullet B;
	float DeltaT = DeltaTime;
	
	if (Bullet_Crashed[0]&&Bullet_Loaded[0]==false&&Bullet_Flying[0]==true)
	{
		B.Move(bullet0[0].angle, &bullet0[0].BulletX, &bullet0[0].BulletY, bullet0[0].Power, DeltaT);
	}
	else if (Bullet_Crashed[1]&&Bullet_Loaded[1] == false&&Bullet_Flying[1] == true)
	{
		B.Move(bullet0[1].angle, &bullet0[1].BulletX, &bullet0[1].BulletY, bullet0[1].Power, DeltaT);
	}
	else if (Bullet_Crashed[2]&&Bullet_Loaded[2] == false && Bullet_Flying[2] == true)
	{
		B.Move(bullet0[2].angle, &bullet0[2].BulletX, &bullet0[2].BulletY, bullet0[2].Power, DeltaT);
	}
	else if (Bullet_Crashed[3]&& Bullet_Loaded[0] == false && Bullet_Flying[3] == true)
	{
		B.Move(bullet0[3].angle, &bullet0[3].BulletX, &bullet0[3].BulletY, bullet0[3].Power, DeltaT);
	}
	else
	{
			
	}
}
void Player::Player_BulletCrashed_Reload()
{
	Bullet b;
	for(int i=0;i<BULLET_MAX;i++)
	{
		if (Bullet_Flying[i]==true) 
		{
			Bullet_Crashed[i] = true;
			Bullet_Flying[i] = false;
			Bullet_Loaded[i] = true;

			bullet0[i].angle = 0;
			bullet0[i].BulletX = Player_XPos;
			bullet0[i].BulletY = Player_YPos;
			bullet0[i].Power = 0;
		}
	}
	b.~Bullet();
	for (int i=0;i<BULLET_MAX;i++)   //������ 
	{
		if (Bullet_Crashed[i]==true) 
		{
			Bullet_Crashed[i] = false;
		}
	}
}
void Player::PlayerHealthDecrease_Dead()
{
	life--;
	if(life==0)
	{
		dead == true;
	}
}
Player::~Player() 
{
	life = 0;
	dead = true;
}