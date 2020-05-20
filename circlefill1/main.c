#include <stdlib.h>

#include <SDL2/SDL.h>
#include "colorspec.h"
#include "circlefill.h"

#define WINDOW_WIDTH 1366
#define WINDOW_HEIGHT 768

int main(void) {
    struct thecolorspec red = { 255, 0, 0, 0 };
    int quit = 0;
    int theradius1 = 200;
    SDL_Event event;
    SDL_Renderer *renderer;
    SDL_Window *window;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer);
	 SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    
    circlefill(renderer, WINDOW_WIDTH/2, WINDOW_HEIGHT/2, theradius1, &red);
    
    SDL_RenderPresent(renderer);
    
    while(!quit) 
    {
        SDL_PollEvent(&event);

        switch(event.type)
        {
        case SDL_QUIT:
        	quit = 1;
        	break;
        case SDL_KEYDOWN:
        		switch(event.key.keysym.sym) {
        		case SDLK_ESCAPE:
        			quit = 1;
        			break;
        		}
       	}
    }
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}

