#include <SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	SDL_Window *window = NULL;
	SDL_Surface *screenSurface = NULL;
	int quit = 0;
	SDL_Event e;
	int color = 1;

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
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0, 200, 30));
	SDL_UpdateWindowSurface(window);

	while (quit == 0)
	{
		switch (color)
		{
		case 1:
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 255, 0, 0));
			SDL_UpdateWindowSurface(window);
			break;
		case 2:
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0, 0, 255));
			SDL_UpdateWindowSurface(window);
			break;
		case 3:
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0, 200, 30));
			SDL_UpdateWindowSurface(window);
			color = 0;
			break;
		default:
			color = 0;
			break;
		}
		color++;
		SDL_Delay(100);
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
				quit = 1;
		}	
		
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}