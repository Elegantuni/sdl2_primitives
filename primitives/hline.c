#include "hline.h"

int hline(SDL_Renderer* renderer, int x1, int y1, int x2, struct thecolorspec *thecolor)
{
	SDL_SetRenderDrawColor(renderer, thecolor->red, thecolor->green, thecolor->blue, thecolor->alpha);
	
	if(x1 <= x2)
	{
		for(int i = x1; i <= x2; i++)
		{
			SDL_RenderDrawPoint(renderer, i, y1);
		}

		return 0;
	}
	else if(x1 >= x2)
	{
		for(int i = x2; i <= x1; i++)
		{
			SDL_RenderDrawPoint(renderer, i, y1);
		}

		return 0;
	}
}

