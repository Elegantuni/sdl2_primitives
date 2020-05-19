#ifndef __CIRCLE_H
#define __CIRCLE_H

#include <SDL2/SDL.h>
#include "colorspec.h"
#include <math.h>

int circle(SDL_Renderer* renderer, int x1, int y1, int radius, struct thecolorspec *thecolor);

#endif

