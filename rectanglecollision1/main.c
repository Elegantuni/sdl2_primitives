#include <stdlib.h>

#include <SDL2/SDL.h>

#include "xynormrectangle.h"
#include "colorspec.h"

#include "rectanglecollision.h"

#define WINDOW_WIDTH 1366
#define WINDOW_HEIGHT 768

int main(void) {
	 struct thecolorspec red = {255, 0, 0, 0};
	 struct thecolorspec blue = {0, 0, 255, 0};
	 struct thecolorspec black = {0, 0, 0, 0};
	 int quit = 0;
	 struct rectangle rect1;
	 struct rectangle rect2;
	 struct rectangle rect1temp;
	 rect1.x1 = 0;
	 rect1.x2 = 10;
	 rect1.y1 = 0;
	 rect1.y2 = 10;
	 rect1.color = red;
	 rect1.alive = 1;
	 rect2.x1 = 30;
	 rect2.x2 = 10;
	 rect2.y1 = 30;
	 rect2.y2 = 10;
	 rect2.color = blue;
	 rect2.alive = 1;
	 rect1temp = rect1;
    SDL_Event event;
    SDL_Renderer *renderer;
    SDL_Window *window;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer);
	 SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    xynormrectangle(renderer, rect1.x1, rect1.x2, rect1.y1, rect1.y2, &rect1.color);
    xynormrectangle(renderer, rect2.x1, rect2.x2, rect2.y1, rect2.y2, &rect2.color);

    SDL_RenderPresent(renderer);
    
    while(!quit) 
    {
    	  rect1temp = rect1;
    	  
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
        		case SDLK_a:
        			xynormrectangle(renderer, rect1.x1, rect1.x2, rect1.y1, rect1.y2, &black);

        			rect1.x1--;

        			if(rect1.x1 < 0)
        			{
        				rect1.x1 = 0;
        			}
        			break;
        		case SDLK_d:
        			xynormrectangle(renderer, rect1.x1, rect1.x2, rect1.y1, rect1.y2, &black);

        			rect1.x1++;

        			if(rect1.x1 + 10 > WINDOW_WIDTH - 1)
        			{
        				rect1.x1 = WINDOW_WIDTH - 1 - 10;
        			}
        			break;
        		case SDLK_w:
        			xynormrectangle(renderer, rect1.x1, rect1.x2, rect1.y1, rect1.y2, &black);

        			rect1.y1--;

        			if(rect1.y1 < 0)
        			{
        				rect1.y1 = 0;
        			}
        			break;
        		case SDLK_s:
        			xynormrectangle(renderer, rect1.x1, rect1.x2, rect1.y1, rect1.y2, &black);

        			rect1.y1++;

        			if(rect1.y1 + 10 > WINDOW_HEIGHT - 1)
        			{
        				rect1.y1 = WINDOW_HEIGHT - 1 - 10;
        			}
        			break;
       	}

			if(rectanglecollision(rect1, rect2) == 0 && rect2.alive == 1)
			{
       		xynormrectangle(renderer, rect1.x1, rect1.x2, rect1.y1, rect1.y2, &rect1.color);
       		xynormrectangle(renderer, rect2.x1, rect2.x2, rect2.y1, rect2.y2, &rect2.color);
       	}
       	else if(rectanglecollision(rect1, rect2) == 1 && rect2.alive == 1)
       	{
				xynormrectangle(renderer, rect2.x1, rect2.x2, rect2.y1, rect2.y2, &black);
				xynormrectangle(renderer, rect1.x1, rect1.x2, rect1.y1, rect1.y2, &rect1.color);
				
       		rect2.alive = 0;
       	}
       	else
       	{
       		xynormrectangle(renderer, rect1.x1, rect1.x2, rect1.y1, rect1.y2, &rect1.color);
       	}
       	
       	SDL_RenderPresent(renderer);
       } 
    }
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}

