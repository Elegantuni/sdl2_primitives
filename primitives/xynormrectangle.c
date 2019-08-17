#include "xynormrectangle.h"

int xynormrectangle(SDL_Renderer *renderer, int x1, int sizex, int y1, int sizey, struct thecolorspec *thecolor)
{
	hline(renderer, x1, y1, x1+sizex, thecolor);
	hline(renderer, x1, y1+sizey, x1+sizex, thecolor);
	vline(renderer, x1, y1, y1+sizey, thecolor);
	vline(renderer, x1+sizex, y1, y1+sizey, thecolor);

	return 0;
}
