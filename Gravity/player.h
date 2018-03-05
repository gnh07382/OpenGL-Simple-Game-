#pragma once
#ifndef __PLAYER_H_
#define __PLAYER_H_


class Player 
{
	
public:
	Player();
	~Player();
	
	void bullet(float DeltaTime); //bullet move
	void upgun();
	void downgun();
	void render();
	void PowerUpDown();
	void fire();
	
	int life;
	bool dead;

	float Player_XPos;
	float Player_YPos;
	
	float XSize;
	float YSize;

	struct Bullet_0
	{
		float angle;
		float BulletX;//bullet위치
		float BulletY;
		float Power;
	};
	/*struct Bullet_1
	{
		float angle;
		float BulletX;//bullet위치
		float BulletY;
		float Power;
	};
	struct Bullet_2
	{
		float angle;
		float BulletX;//bullet위치
		float BulletY;
		float Power;
	}; struct Bullet_3
	{
		float angle;
		float BulletX;//bullet위치
		float BulletY;
		float Power;
	};*/
	struct Bullet_0 bullet0[4];
	/*
	struct Bullet_1 bullet1;
	struct Bullet_2 bullet2;
	struct Bullet_3 bullet3;
	*/
private:

	bool Bullet_Loaded[4];
	bool Bullet_Crashed[4];
	bool Bullet_Flying[4];
	
	void PlayerHealthDecrease_Dead();
	void Player_BulletCrashed_Reload();
};

#endif // !__PLAYER_H_
