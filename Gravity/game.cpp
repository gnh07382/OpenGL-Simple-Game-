//게임 화면 내 있는것들(게임 장면, 나가기 버튼)
#include "enemy.h"
#include "game.h"
#include "player.h" 
#include "bullet.h"
#include <gl/freeglut.h>

#define Bullet_Max 4

Bullet B;

Game::Game() 
{
	gameover = false;
	gamerunning = false;
}
void Game::Render(float DeltaTime)
{
	Player P;
	Enemy E;
	P.bullet(DeltaTime);
	E.EnemyMove(DeltaTime);
}
void Game::RenderButton()//일시정지 버튼 
{

}
void Game::Status() //게임 상태 표시줄 (파워나 fps 체력 표시)
{

}
Game::~Game() 
{
	gameover = true;
	gamerunning = false;
}