#include <SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	SDL_Window *window = NULL;
	SDL_Surface *screenSurface = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! Error: %s\n", SDL_GetError());
		SDL_Quit();
		return 0;
	}

	window = SDL_CreateWindow("Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		printf("Window could not be created! Error: %s\n", SDL_GetError());
		SDL_Quit();
		return 0;
	}

	screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 255, 255, 255));
	SDL_UpdateWindowSurface(window);

	SDL_Delay(2000);

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}