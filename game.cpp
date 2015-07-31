#include <SDL.h>
#include <stdio.h>
#include "game.h"

int GameData::Setup()
{
		if(SDL_Init (SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL Error: %s\n", SDL_GetError() );
		return -1;
	}

	if ((mWindow = SDL_CreateWindow("Maps", 200,200,800,600,0)) == NULL)
	{
		printf("SDL Error%s\n", SDL_GetError());
		return -1;
	}

	if((mScreenSurface = SDL_GetWindowSurface(mWindow)) == NULL)
	{
		printf("SDL Error%s\n", SDL_GetError());
		return -1;
	}
		if((mGameSurface = SDL_LoadBMP("img/map.bmp")) == NULL)
	{
		printf("SDL Error%s\n", SDL_GetError());
		return -1;
	}
		return 0;
		
		if ((mWindow = SDL_CreateWindow("Characters", 200,200,800,600,0)) == NULL)
	{
		printf("SDL Error%s\n", SDL_GetError());
		return -1;
	}

	if((nScreenSurface = SDL_GetWindowSurface(nWindow)) == NULL)
	{
		printf("SDL Error%s\n", SDL_GetError());
		return -1;
	}
		if((nGameSurface = SDL_LoadBMP("img/character.bmp")) == NULL)
	{
		printf("SDL Error%s\n", SDL_GetError());
		return -1;
	}
		return 0;
}

int GameData::Draw()
{
	SDL_BlitSurface (mGameSurface, NULL, mScreenSurface, NULL);
	SDL_BlitSurface (nGameSurface, NULL, nScreenSurface, NULL);
	SDL_UpdateWindowSurface(mWindow);
	SDL_UpdateWindowSurface(nWindow);
	return 0;
}

int GameData::Input()
{
	SDL_Event e;
	SDL_PollEvent(&e);
	if(e.type == SDL_QUIT)
		mDone = true;
	return 0;
}

int GameData::Update()
{
	//Nothing yet..
	return 0;
}

int GameData::Run()
{
	do
	{
		Input();
		Update();
		Draw();
		SDL_Delay(10);
	}while(!mDone);
	return 0;
}

int GameData::Shutdown()
{
	SDL_FreeSurface(mGameSurface);
	SDL_DestroyWindow (mWindow);
	SDL_FreeSurface(nGameSurface);
	SDL_DestroyWindow (nWindow);
	SDL_Quit();
	return 0;
}