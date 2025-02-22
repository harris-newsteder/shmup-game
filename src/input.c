#include "input.h"

#include <SDL3/SDL_events.h>

static _Bool _thisTickInputs[4] = { 0 };
static _Bool _lastTickInputs[4] = { 0 };

void input_handle_event(SDL_Event *event)
{
	switch (event->type)
	{
	case SDL_EVENT_KEY_DOWN:
	{
		switch (event->key.key)
		{
		case SDLK_W:
			_thisTickInputs[INPUT_UP] = 1;
			break;
		case SDLK_A:
			_thisTickInputs[INPUT_LEFT] = 1;
			break;
		case SDLK_S:
			_thisTickInputs[INPUT_DOWN] = 1;
			break;
		case SDLK_D:
			_thisTickInputs[INPUT_RIGHT] = 1;
			break;
		}
		break;
	}
	case SDL_EVENT_KEY_UP:
	{
		switch (event->key.key)
		{
		case SDLK_W:
			_thisTickInputs[INPUT_UP] = 0;
			break;
		case SDLK_A:
			_thisTickInputs[INPUT_LEFT] = 0;
			break;
		case SDLK_S:
			_thisTickInputs[INPUT_DOWN] = 0;
			break;
		case SDLK_D:
			_thisTickInputs[INPUT_RIGHT] = 0;
			break;
		}
		break;
	}
	}
}

void input_tick(void)
{
	for (int i = 0; i < 4; i++)
	{
		_lastTickInputs[i] = _thisTickInputs[i];
	}
}

_Bool input_down(int input)
{
	return _thisTickInputs[input];
}

_Bool input_up(int input)
{
	return !_thisTickInputs[input];
}

_Bool input_pressed(int input)
{
	return _thisTickInputs[input] && !_lastTickInputs[input];
}

_Bool input_released(int input)
{
	return !_thisTickInputs[input] && _lastTickInputs[input];
}