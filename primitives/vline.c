#include "vline.h"

int vline(SDL_Renderer *renderer, int x1, int y1, int y2, struct thecolorspec *thecolor)
{
	SDL_SetRenderDrawColor(renderer, thecolor->red, thecolor->green, thecolor->blue, thecolor->alpha);
	
	if(y1 <= y2)
	{
		for(int i = y1; i <= y2; i++)
		{
			SDL_RenderDrawPoint(renderer, x1, i);
		}

		return 0;
	}
	else if(y1 >= y2)
	{
		for(int i = y2; i <= y1; i++)
		{
			SDL_RenderDrawPoint(renderer, x1, i);
		}

		return 0;
	}
}

