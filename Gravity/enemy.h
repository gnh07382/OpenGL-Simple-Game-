#pragma once
#ifndef __ENEMY_H__
#define __ENEMY_H__

class Enemy
{
public:
	int TotalEnemyKilled;
	int EnemyTotal_1;
	int EnemyTotal_2;
	int EnemyTotal_3;

	void colide();                //포탄 충돌시
	void offencesucceed();        //플레이어 방어벽 부딫힐때
	void killcount();             //돈세기

	void EnemyMove(float Delta_T);             //움직임

private:
	
	void EnemyCreate();
	void EnemyDestroy();
	void Render();
	
	int i0, i1, i2;        //i0==enemy1,   i1==enemy2,    i2==enemy3

	bool EnemyCreated_1[15];
	bool EnemyCreated_2[5];
	bool EnemyCreated_3[1];

	struct Enemy1
	{
		float XPos, YPos;
		float XSize, YSize;
		bool IsDead;
		int Health;
		float EnemySpeed;
	};
	struct Enemy2
	{
		float XPos, YPos;
		float XSize, YSize;
		bool IsDead;
		int Health;
		float EnemySpeed;
	};
	struct Enemy3
	{
		float XPos, YPos;
		float XSize, YSize;
		bool IsDead;
		int Health;
		float EnemySpeed;
	};
	struct Enemy1 enemy1[15];
	struct Enemy2 enemy2[5];
	struct Enemy3 enemy3[1];
};

#endif // !__ENEMY_H__
