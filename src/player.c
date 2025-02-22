#include "player.h"

#include "draw.h"
#include "input.h"

Player player = {
	.x = 0,
	.y = 0,
};

void player_tick(void)
{
	if (input_down(INPUT_RIGHT))
	{
		player.x += 1;
	}

	if (input_down(INPUT_LEFT))
	{
		player.x -= 1;
	}

	if (input_down(INPUT_UP))
	{
		player.y -= 1;
	}

	if (input_down(INPUT_DOWN))
	{
		player.y += 1;
	}
}

void player_draw(void)
{
	draw_rect(player.x, player.y, 32, 16);
}