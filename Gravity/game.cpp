//���� ȭ�� �� �ִ°͵�(���� ���, ������ ��ư)
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
void Game::RenderButton()//�Ͻ����� ��ư 
{

}
void Game::Status() //���� ���� ǥ���� (�Ŀ��� fps ü�� ǥ��)
{

}
Game::~Game() 
{
	gameover = true;
	gamerunning = false;
}