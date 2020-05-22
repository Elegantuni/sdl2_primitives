////////////////////////////////////////////////////////////////////////////////////////
// Game Programming All In One, Third Edition
// Chapter 3 - Particles Program (SDL2 instead of allegro4)
////////////////////////////////////////////////////////////////////////////////////////

#include <math.h>
#include <SDL2/SDL.h>
#include "circlefill.h"
#include <time.h>
#include <stdlib.h>

#define NUM 200

struct thecolorspec black = {0, 0, 0, 0};
struct thecolorspec red = {255, 0, 0, 0};
struct thecolorspec green = {0, 255, 0, 0};
int SCREEN_W = 640;
int SCREEN_H = 480;

//particle structure
struct particle
{
	double mass;
	double x, y;
	long oldX, oldY;
	long xp;
	long yp;
	double ax;
	double ay;
	double vx;
	double vy;

}p[NUM];

int CX, CY;

void resetparticle(int n);
void updateparticles();
void resetall();

void attract(struct particle *A, struct particle *B)
{
	double distance;
	double dist, distX, distY;
	double transX, transY;

	//increase position by velocity value
	A->x += A->vx;
	A->y += A->vy;

	//calculate distance between particles
	distX = A->x - B->x;
	distY = A->y - B->y;
	dist = distX * distX + distY * distY;
	if(dist != 0)
		distance = 1 / dist;
	else
		distance = 0;

	transX = distX * distance;
	transY = distY * distance;

	//acceleration = mass * distance
	A->ax = -1 * B->mass * transX;
	A->ay = -1 * B->mass * transY;

	//increase velocity by acceleration value
	A->vx += A->ax;
	A->vy += A->ay;

	//scale position to the screen
	A->xp = CX + A->x;// - p[0].x;
	A->yp = CY + A->y;// + p[0].y;

}

void resetparticle(int n)
{
	p[n].mass = 0.001;
	p[n].ax = 0;
	p[n].ay = 0;
	p[n].xp = 0;
	p[n].yp = 0;
	p[n].x = rand() % SCREEN_W/4;
	p[n].y = rand() & SCREEN_H/4;
	p[n].vx = 0;
	p[n].vy = 0;
}

void resetall()
{
	int n;
	CX = SCREEN_W / 2;
	CY = SCREEN_H / 2;

	for(n = 0; n < NUM; n++)
		resetparticle(n);
}

int main(void)
{
	int ret;

	//initialize some stuff
	int quit = 0;
	SDL_Event event;
	SDL_Renderer *renderer;
	SDL_Window *window;
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(SCREEN_W, SCREEN_H, 0, &window, &renderer);
	SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	
	srand(time(NULL));
	
	resetall();
	
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

	   int n;
        int i;

        //erase old particle
        for(n = 0; n < NUM; n++)

        //calculate gravity for each particle
        for(n = 0; n < NUM; n++)
        {
                circlefill(renderer, p[n].oldX, p[n].oldY, 5, &black);

                //apply gravity between every particle
                for(i = 0; i < NUM; i++)
                {
                        if(i != n)
                                attract(&p[n], &p[i]);
                }

                //reset particle if it gets too far away
		if(p[n].xp < -1000 ||
                        p[n].xp > 1000 ||
                        p[n].yp < -1000 ||
                        p[n].yp > 1000)
                {
                        resetparticle(n);
                }

                //plot the new particle
                circlefill(renderer, p[n].xp, p[n].yp, 4, &red);

                //keep track of the current position
                p[n].oldX = p[n].xp;
                p[n].oldY = p[n].yp;
        }

        //draw the primary particle
        circlefill(renderer, p[0].xp, p[0].yp, 5, &green);

        SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
}

