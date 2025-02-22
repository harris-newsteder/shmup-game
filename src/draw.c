#include "draw.h"

#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>

static SDL_Renderer *_renderer;

void draw_init(SDL_Renderer *renderer)
{
	_renderer = renderer;
	SDL_SetRenderLogicalPresentation(_renderer, DRAW_WIDTH, DRAW_HEIGHT, SDL_LOGICAL_PRESENTATION_INTEGER_SCALE);
}

void draw_start(void)
{
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(_renderer);
	SDL_SetRenderDrawColor(_renderer, 255, 255, 0, SDL_ALPHA_OPAQUE);
}

void draw_end(void)
{
	SDL_RenderPresent(_renderer);
}

void draw_rect(unsigned x, unsigned y, unsigned w, unsigned h)
{
	static SDL_FRect r;
	r.x = (float)x;
	r.y = (float)y;
	r.w = (float)w;
	r.h = (float)h;
	SDL_RenderRect(_renderer, &r);
}