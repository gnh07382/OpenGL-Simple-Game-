#include <gl/freeglut.h>
#include <windows.h>
#include <time.h>
#include "game.h"
#include "player.h"
#include "bullet.h"


#define width 1280
#define height 720

const int XWindowSize = GetSystemMetrics(SM_CXFULLSCREEN);
const int YWindowSize = GetSystemMetrics(SM_CYFULLSCREEN);//화면 중앙에 위치

void Game_Render() 
{
	float LastTime = (float)clock();     //초단위 반환
	float DeltaTime = 0.0f;              //렌더함수를 지나면서 걸리는 시간 얻기

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Game G;
    G.Render(DeltaTime);
	
	char FPSString[20] = {0};
	int time, timebase=0, frame=0;
	time = glutGet(GLUT_ELAPSED_TIME);
	frame++;
	if (time - timebase > 1000) 
	{
		sprintf_s(FPSString,"FPS: %.2f",frame*1000.0/(time-timebase));
		timebase = time;
		frame = 0;
	}                                    //FPS(보여주기용) 계산


	float curtime = (float)clock();      //프레임 측정
	DeltaTime = curtime - LastTime;
	
	glutSwapBuffers();
}
void Game_MouseFunc(int button, int state, int x, int y) 
{

}
void Game_KeyBoardFunc(unsigned char key, int x, int y) 
{
	Player p;
	if (key==27) 
	{
		glutLeaveGameMode();
		exit(1);
	}
	else if (key == 32)//spacebar 파워조정
	{
		p.PowerUpDown();
	}
	else if (key==13)//enter(발사)
	{
		p.fire();
	}
	else 
	{
	
	}
}
void Game_SpecialFunc(int key, int x, int y) 
{
	Player P;
	switch (key)            //위,아래==포각조절   옆: 포탄조절
	{
	case GLUT_KEY_UP:
		P.upgun();
		break;
	case GLUT_KEY_DOWN:
		P.downgun();
		break;
	case GLUT_KEY_LEFT:      //탄종변경

		break;
	case GLUT_KEY_RIGHT:

		break;
	default:
		break;
	}
}
int main(int argc, char **argv)
{

    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
	glutInitWindowPosition((XWindowSize-width)/2,(YWindowSize-height)/2);
	//glutInitWindowSize(width, height);
	//glutCreateWindow("Gravity");
	glutGameModeString("1024*700:32");
	if (glutGameModeGet(GLUT_GAME_MODE_POSSIBLE)) 
      glutEnterGameMode();
	else 
	{
		glutInitWindowSize(width, height);
		glutCreateWindow("Gravity");
	}

	while (1)
	{
		glutDisplayFunc(Game_Render);
		glutIdleFunc(Game_Render);
		glutMouseFunc(Game_MouseFunc);
		glutKeyboardFunc(Game_KeyBoardFunc);
		glutSpecialFunc(Game_SpecialFunc);
		glutMainLoopEvent();
	}                                                      //게임 모드

    return 0;
}