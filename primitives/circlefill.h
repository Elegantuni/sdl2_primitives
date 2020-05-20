#ifndef __CIRCLEFILL_H
#define __CIRCLEFILL_H

#include <SDL2/SDL.h>
#include "colorspec.h"
#include <math.h>

int circlefill(SDL_Renderer* renderer, int x1, int y1, int radius, struct thecolorspec *thecolor);

#endif

