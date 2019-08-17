#ifndef __LINE_H
#define __LINE_H

#include <SDL2/SDL.h>
#include "colorspec.h"

int line(SDL_Renderer *renderer, int x1, int y1, int x2, int y2, struct thecolorspec *thecolor);

void plotLine(SDL_Renderer *renderer, int x1, int y1, int x2, int y2);

void plotLineLow(SDL_Renderer *renderer, int x1, int y1, int x2, int y2);

void plotLineHigh(SDL_Renderer *renderer, int x1, int y1, int x2, int y2);

#endif

