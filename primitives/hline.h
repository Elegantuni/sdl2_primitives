#ifndef __HLINE_H
#define __HLINE_H

#include <SDL2/SDL.h>
#include "colorspec.h"

int hline(SDL_Renderer* renderer, int x1, int y1, int x2, struct thecolorspec *thecolor);

#endif

