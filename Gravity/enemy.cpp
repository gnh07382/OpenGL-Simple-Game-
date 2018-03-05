#include "enemy.h"
#include "GL/freeglut.h"
#include <fstream>
#include <iostream>
#include "scene.h"
#include "player.h"

using namespace std;

ofstream output;
ifstream input;

#define ENEMY1_MAX  15
#define ENEMY2_MAX  3      
#define ENEMY3_MAX  1

const float StageHardConstant = 1.08;   //각 단계마다 1.08배씩 난이도 상승
const int StageOneInfantBornTime = 1000;   //1단계일때 1초마다 보병 하나씩 나옴,밀리세컨드 단위
const int WhenTankAppears = 5;          //스테이지 5에서 탱크 나옴
const int WhenB29Appears = 15;          //스테이지 15 폭격기 나옴

const float InfantSpeed=0.001f;         //총알 속도:0.02*60= 1초에 화면 절반 날아감
const float TankSpeed = 0.002f;
const float BomberSpeed = 0.005f;

void Enemy::Render()
{
	
}
void Enemy::EnemyCreate()  //60프레임이니까 프레임값 얻어와서 일정주기로 만들기, 단계별 난이도 조정
{
	int Stage;
	Scene Scene;

	ifstream input;                //file io로 스테이지 읽어오기
	input.open("StageInfo.txt");
	if (input.fail)                 //에러 발생 시
		cout <<"no StageInfo.txt file found"<<endl;

	while(input.eof==false)
	{
		input >> Stage;
	}
	
	int time1, framecnt1 = 0, timebase1 = 0;
	int time2, framecnt2 = 0, timebase2 = 0;
	int time3, framecnt3 = 0, timebase3 = 0;
   

	time1 = glutGet(GLUT_ELAPSED_TIME);
	framecnt1++;
	if(time1-timebase1>=StageOneInfantBornTime)
	{
		timebase1 = time1;        
		framecnt1 = 0;
		if (i0<ENEMY1_MAX) 
		{
			enemy1[i0].XPos = 1.0f + (enemy1[i0].XSize / 2);
			enemy1[i0].YPos = Scene.LandHeight + (enemy1[i0].YSize / 2);
			i0++;
			EnemyCreated_1[i0] = true;
		}
	}
	if (Stage>=WhenTankAppears) 
	{
		time2 = glutGet(GLUT_ELAPSED_TIME);
		framecnt2++;
		if(time2-timebase2>=(StageOneInfantBornTime)*5)
		{
			timebase2 = time2;
			framecnt2++;
			if(i1<ENEMY2_MAX)
			{
				enemy2[i1].XPos = 1.0f + (enemy2[i1].XSize/2);
				enemy2[i1].YPos = Scene.LandHeight + (enemy2[i1].YSize / 2);
				i1++;
				EnemyCreated_2[i1] = true;
			}
		}
	}
	if (Stage>=WhenB29Appears) 
	{
		time3 = glutGet(GLUT_ELAPSED_TIME);
		framecnt3++;
		if (time3-timebase3>=(StageOneInfantBornTime)*15)
		{
			if (i2 < ENEMY3_MAX)
			{
				enemy3[i2].XPos = 1.0f + (enemy3[i2].XSize / 2);
				enemy3[i2].YPos = Scene.LandHeight + (enemy3[i2].YSize / 2);
				i2++;
				EnemyCreated_3[i2] = true;
			}
		}
	}
}
void Enemy::EnemyMove(float Delta_T)
{
	Player player;

	int j0, j1, j2;
	if (EnemyCreated_1[j0]==true&&enemy1[j0].IsDead==false) 
	{
		if (player.Player_XPos+(player.XSize/2)<=enemy1[j0].XPos) 
		{
			enemy1[j0].XPos += InfantSpeed;
			//EnemyZ->IsDead = true;                  //테스트용
		}
	}
	j0++;
	if (EnemyCreated_2[j1] == true && enemy2[j1].IsDead == false)
	{
		if (player.Player_XPos + (player.XSize / 2) <= enemy2[j1].XPos)
		{
			enemy2[j1].XPos += InfantSpeed*2;
		}
	}
	j1++;
	if (EnemyCreated_3[j2] == true && enemy3[j2].IsDead == false)
	{
		if (player.Player_XPos + (player.XSize / 2) <= enemy2[j2].XPos)
		{
			enemy3[j2].XPos += InfantSpeed*4;
		}
	}
	j2++;
}
void Enemy::colide()            //아군 포탄 충돌시
{
	Player player;
	for (int i = 0; i < ENEMY1_MAX; i++)
	{
		if(enemy1[i].XPos-(enemy1[i].XSize/2) <= player.bullet0->BulletX && enemy1->YPos)//작성중
		{
					
		}
	}
}
void Enemy::EnemyDestroy()       //적 체력 감소->사망시
{

}
void Enemy::offencesucceed()    //적 공격 성공시
{
	
}
void Enemy::killcount()
{

}