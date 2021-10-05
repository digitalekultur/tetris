#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef int8_t s8;
typedef int32_t s32;
typedef float f32;
typedef double f64;

#define WIDTH 7
#define HEIGHT VISIBLE_HEIGHT + 2 // two lines are hidden to spawn new elements
#define VISIBLE_HEIGHT 20

struct Game_State
{
  u8 board[WIDTH * HEIGHT];
};

inline u8 matrix_get(const u8 *values, s32 width, s32 row, s32 col)
{
  s32 index = row * width + col;
  return values[index];
}

inline void matrix_get(u8 *values, s32 width, s32 row, s32 col, u8 value)
{
  s32 index = row * width + col;
  values[index] = value;
}

void update_game_play(Game_State *game)
{
}

void update_game(Game_State *game)
{
  switch (game->phase)
  {
  case GAME_PHASE_PLAY:
    return update_game_play(game);
    break;
  }
}
int main()
{
  return 0;
}