#ifndef _RP4_INPUT_H_
#define _RP4_INPUT_H_

#define INPUT_UP 0
#define INPUT_DOWN 1
#define INPUT_LEFT 2
#define INPUT_RIGHT 3

union SDL_Event;

extern void input_handle_event(union SDL_Event*);
extern void input_tick(void);

extern _Bool input_down(int);
extern _Bool input_up(int);
extern _Bool input_pressed(int);
extern _Bool input_released(int);

#endif /* _RP4_INPUT_H_ */