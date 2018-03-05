#ifndef __GAME_H__
#define __GAME_H__

class Game
{
public:
	Game();
	~Game();
	
	void Render(float DeltaTime);
	
private:
	void RenderButton();
	void Status();

	bool gameover;
	bool gamerunning;
};
#endif // !__game_h_
