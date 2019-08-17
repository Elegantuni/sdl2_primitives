#include "xynormsquare.h"

int xynormsquare(SDL_Renderer *renderer, int x1, int y1, int size, struct thecolorspec *thecolor)
{
	hline(renderer, x1, y1, x1+size, thecolor);
	hline(renderer, x1, y1+size, x1+size, thecolor);
	vline(renderer, x1, y1, y1+size, thecolor);
	vline(renderer, x1+size, y1, y1+size, thecolor);

	return 0;
}
