#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int		main(int argc, char** argv)
{
	SDL_Rect goutes[50];

	SDL_Init(SDL_INIT_VIDEO);
	SDL_Event event;
	srand(time(NULL));

	SDL_Window *window = SDL_CreateWindow("Une pluie en C/SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
	SDL_Surface *s = SDL_GetWindowSurface(window);

	// On lance tout le système de pluie
	while (1)
	{
		while (SDL_PollEvent(&event)) // Récupération des actions de l'utilisateur
		{
			switch(event.type)
			{
				case SDL_QUIT:
					SDL_DestroyWindow(window);
					SDL_Quit();
					return 0;
					break;
			}
		}
		SDL_FillRect(s, NULL, SDL_MapRGB(s->format, 241, 241, 241));
		for (int i = 0; i < 50; i++)
		{
			if (goutes[i].y + goutes[i].h > s->h)
			{
				goutes[i].w = 1;
				goutes[i].h = rand() % 13;
				goutes[i].h = goutes[i].h + 10;
				goutes[i].x = rand() % s->w; // Chiffre random entre 0 et la taille de la fenetre
				goutes[i].y = rand() % 1000; // Chiffre random entre 0 et 200
				goutes[i].y = goutes[i].x - (goutes[i].x * 2); // On met la hauteur en négatif
			}
			else
			{
				goutes[i].y++;
			}
			SDL_FillRect(s, &goutes[i], SDL_MapRGB(s->format, 70, 130, 180));
		}
		SDL_UpdateWindowSurfaceRects(window, goutes, 50);
	}

	SDL_Quit();
	return 0;

}