#ifndef __RECTANGLECOLLISION_H
#define __RECTANGLECOLLISION_H

#include <SDL2/SDL.h>
#include "colorspec.h"

struct rectangle
{
	int x1;
	int x2;
	int y1;
	int y2;
	struct thecolorspec color;
	int alive;
};

int rectanglecollision(struct rectangle data1, struct rectangle data2);

#endif

