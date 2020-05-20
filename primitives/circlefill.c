#include "circlefill.h"

int circlefill(SDL_Renderer* renderer, int x1, int y1, int radius, struct thecolorspec *thecolor)
{
	SDL_SetRenderDrawColor(renderer, thecolor->red, thecolor->green, thecolor->blue, thecolor->alpha);
	
	if(radius > 0)
	{
		
		double x;
		double y;
		int chy;
		int diff;
		double theradius;
		
		for(double i = 0; i <= radius; i=i+1)
		{
			for(double j = 0; j <= i; j=j+0.01)
			{
				y = sqrt(i * i - (x1 - x1) * (x1 - x1)) + y1;

				chy = (int)y;

				if(chy < 0)
				{
					chy = -1 * chy;
				}

				SDL_RenderDrawPoint(renderer, x1, chy);

				diff = chy - y1;

				if(diff < 0)
				{
					diff = -1 * diff;
				}

				SDL_RenderDrawPoint(renderer, x1, chy - diff - diff);
			
				y = sqrt(i * i - ((x1 - j) - x1) * ((x1 - j) - x1)) + y1;

				chy = (int)y;

				if(chy < 0)
				{
					chy = -1 * chy;
				}
			
				SDL_RenderDrawPoint(renderer, (x1 - j), y1);

				SDL_RenderDrawPoint(renderer, (x1 - j), chy);

				diff = chy - y1;

				if(diff < 0)
				{
					diff = -1 * diff;
				}
			
				SDL_RenderDrawPoint(renderer, (x1 - j), chy - diff - diff);

				y = sqrt(i * i - ((x1 + j) - x1) * ((x1 + j) - x1)) + y1;

				chy = (int)y;

				if(chy < 0)
				{
					chy = -1 * chy;
				}
			
				SDL_RenderDrawPoint(renderer, (x1 + j), y1);

				SDL_RenderDrawPoint(renderer, (x1 + j), chy);

				diff = chy - y1;

				if(diff < 0)
				{
					diff = -1 * diff;
				}
			
				SDL_RenderDrawPoint(renderer, (x1 + j), chy - diff - diff);
			}
		}
	}

	return 0;
}

