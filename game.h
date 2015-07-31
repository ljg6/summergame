#ifndef __GAME_H
#define __GAME_H

/**
* The games driver class
*/

class GameData
{
	int mGameState; /**< The state of the game*/
	bool mChanged; /**< Has the screen changed*/
	bool mDone; /**< Has the game end*/
	SDL_Window * mWindow;
	SDL_Window * nWindow;
	SDL_Surface *mScreenSurface;
	SDL_Surface *mGameSurface;
	SDL_Surface *nScreenSurface;
	SDL_Surface *nGameSurface; 
	//Private Methods
	int Input();
	int Update();
	int Draw();
	
public:
	//Constructor and Destructor
	//GameData();
	//~GameData();
	//Public Methods
	int Setup();
	int Run();
	int Shutdown();
};

extern GameData game;

#endif //__GAME_H