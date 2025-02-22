#ifndef _RP4_DRAW_H_
#define _RP4_DRAW_H_

#define DRAW_WIDTH 256
#define DRAW_HEIGHT 224

struct SDL_Renderer;

extern void draw_init(struct SDL_Renderer*);
extern void draw_start(void);
extern void draw_end(void);

extern void draw_rect(unsigned, unsigned, unsigned, unsigned);

#endif /* _RP4_DRAW_H_ */