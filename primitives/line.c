#include "line.h"

int line(SDL_Renderer *renderer, int x1, int y1, int x2, int y2, struct thecolorspec *thecolor)
{
	SDL_SetRenderDrawColor(renderer, thecolor->red, thecolor->green, thecolor->blue, thecolor->alpha);

	double deltax = x2 - x1;
	double deltay = y2 - y1;
	double deltaerr;
	double error = 0;
	int y = y1;
	
	if(x1 < x2 || x1 > x2)
	{
		if(abs(y2 - y1) < abs(x2 - x1))
		{
			if(x1 > x2)
			{
				plotLineLow(renderer, x2, y2, x1, y1);
			}
			else
			{
				plotLineLow(renderer, x1, y1, x2, y2);
			}
		}
		else
		{
			if(y1 > y2)
			{
				plotLineHigh(renderer, x2, y2, x1, y1);
			}
			else
			{
				plotLineHigh(renderer, x1, y1, x2, y2);
			}
		}

		return 0;
	}

	if(x1 == x2)
	{
		if(y1 <= y2)
		{
			for(int i = y1; i <= y2; i++)
			{
				SDL_RenderDrawPoint(renderer, x1, i);
			}

			return 0;
		}
		else if(y1 >= y1)
		{
			for(int i = y2; i <= y1; i++)
			{
				SDL_RenderDrawPoint(renderer, x1, i);
			}

			return 0;
		}
	}
}

void plotLine(SDL_Renderer *renderer, int x1, int y1, int x2, int y2)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	double D = 2*dy - dx;
	int y = y1;

	for(int i = x1; i <= x2; i++)
	{
		SDL_RenderDrawPoint(renderer, i, y);

		if(D > 0)
		{
			y = y + 1;
			D = D - 2 * dx;
		}

		D = D + 2 * dy;
	}
}

void plotLineLow(SDL_Renderer *renderer, int x1, int y1, int x2, int y2)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int yi = 1;

	if(dy < 0)
	{
		yi = -1;
		dy = -dy;
	}

	double D = 2 * dy - dx;
	int y = y1;

	for(int i = x1; i <= x2; i++)
	{
		SDL_RenderDrawPoint(renderer, i, y);

		if(D > 0)
		{
			y = y + yi;
			D = D - 2 * dx;
		}

		D = D + 2 * dy;
	}
}

void plotLineHigh(SDL_Renderer *renderer, int x1, int y1, int x2, int y2)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int xi = 1;

	if(dx < 0)
	{
		xi = -1;
		dx = -dx;
	}

	double D = 2 * dx - dy;
	int x = x1;

	for(int i = y1; i <= y2; i++)
	{
		SDL_RenderDrawPoint(renderer, x, i);

		if(D > 0)
		{
			x = x + xi;
			D = D - 2 * dy;
		}

		D = D + 2 * dx;
	}
}

