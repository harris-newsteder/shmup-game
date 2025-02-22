#ifndef _RP4_PLAYER_H_
#define _RP4_PLAYER_H_

#define PCON_NORMAL 0
#define PCON_HIT_INVUL 1
#define PCON_HIT_CRITICAL 2
#define PCON_CRITICAL 3

typedef struct
{
	unsigned x, y;
	unsigned condition;
	unsigned pwep_sustain;
	unsigned pwep_delay;
} Player;

extern Player player;

extern void player_tick(void);
extern void player_draw(void);

#endif /* _RP4_PLAYER_H_ */