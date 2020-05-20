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
		
		for(double i = 0; i <= radius; i=i+0.1)
		{
			y = sqrt(radius * radius - ((x1 - i) - x1) * ((x1 - i) - x1)) + y1;

			chy = (int)y;

			if(chy < 0)
			{
				chy = -1 * chy;
			}

			diff = chy - y1;

			if(diff < 0)
			{
				diff = -1 * diff;
			}

			for(int j = chy - diff - diff; j <= chy; j++)
			{
				SDL_RenderDrawPoint(renderer, (x1 - i), j);
			}

			for(int j = chy - diff - diff; j <= chy; j++)
			{
				SDL_RenderDrawPoint(renderer, (x1 + i), j);
			} 
		}
	}

	return 0;
}

