#include "SDL.h"
#include "game.h"

/**<
 * Main funcion of the program
 * Param argv The number of arguments it has been started with.
 * 
 * 
*/

GameData game;

int main(int argv, char *args[])
{
	if(game.Setup() <0)
		return -1;
	game.Run();
	game.Shutdown();
	return 0;
}