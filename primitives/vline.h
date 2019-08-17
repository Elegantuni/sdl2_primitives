#ifndef __VLINE_H
#define __VLINE_H

#include <SDL2/SDL.h>
#include "colorspec.h"

int vline(SDL_Renderer *renderer, int x1, int y1, int y2, struct thecolorspec *thecolor);

#endif

