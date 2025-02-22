#define SDL_MAIN_USE_CALLBACKS 1

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "draw.h"
#include "input.h"
#include "timing.h"

typedef struct
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	Uint64 last_tick;
} AppState;

static const struct
{
	const char *key;
	const char *value;
} extended_metadata[] = {
	{SDL_PROP_APP_METADATA_URL_STRING, "https://github.com/harris-newsteder/shmup-game"},
	{SDL_PROP_APP_METADATA_CREATOR_STRING, "Harris Newsteder"},
	{SDL_PROP_APP_METADATA_COPYRIGHT_STRING, ""},
	{SDL_PROP_APP_METADATA_TYPE_STRING, "game"}
};

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{

	size_t i;

	if (!SDL_SetAppMetadata("shmup game", "0.0", "com.newsteder.shmup"))
	{
		return SDL_APP_FAILURE;
	}

	for (i = 0; i < SDL_arraysize(extended_metadata); i++)
	{
		if (!SDL_SetAppMetadataProperty(extended_metadata[i].key, extended_metadata[i].value))
		{
			return SDL_APP_FAILURE;
		}
	}

	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		return SDL_APP_FAILURE;
	}

	AppState *as = (AppState *)SDL_calloc(1, sizeof(AppState));
	if (!as)
	{
		return SDL_APP_FAILURE;
	}

	*appstate = as;

	if (!SDL_CreateWindowAndRenderer("shmup game", 1024, 896, 0, &as->window, &as->renderer))
	{
		return SDL_APP_FAILURE;
	}

	draw_init(as->renderer);
	as->last_tick = SDL_GetTicks();

	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
	switch (event->type)
	{
	case SDL_EVENT_QUIT:
		return SDL_APP_SUCCESS;
	}

	input_handle_event(event);
	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate)
{
	AppState *as = (AppState *)appstate;

	if (SDL_GetTicks() - as->last_tick >= TICK_TIME)
	{
		player_tick();
		input_tick();
		as->last_tick += TICK_TIME;
	}

	draw_start();
	// drawing routines
	player_draw();
	draw_end();


	return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
	if (appstate != NULL)
	{
		AppState *as = (AppState *)appstate;
		SDL_DestroyRenderer(as->renderer);
		SDL_DestroyWindow(as->window);
		SDL_free(as);
	}
}