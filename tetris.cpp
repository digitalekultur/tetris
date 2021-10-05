#include <cstdlib>
#include <cstdint>
#include <cstdio>
#include <cstring>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef int8_t s8;
typedef int32_t s32;
typedef float f32;
typedef double f64;

#define WIDTH 7
#define HEIGHT 22 // two lines are hidden to spawn new elements
#define VISIBLE_HEIGHT 20

struct Tetrino
{
  const u8 *data;
  const s32 side;
};

inline Tetrino // constructor function
tetrino(const u8 *data, s32 side)
{
  return {data, side};
}

// Tetrino shapes (required to be squares)

const u8 TETRINO_1[] = {
    0, 0, 0, 0,
    1, 1, 1, 1,
    0, 0, 0, 0,
    0, 0, 0, 0};

const u8 TETRINO_2[] = {
    2, 2,
    2, 2};

const u8 TETRINO_3[] = {
    0, 0, 0,
    3, 3, 3,
    0, 3, 0};

const Tetrino TETRINOS[] = {
    tetrino(TETRINO_1, 4),
    tetrino(TETRINO_2, 3),
    tetrino(TETRINO_3, 3)};

enum Game_Phase
{
  GAME_PHASE_PLAY
};

struct Piece_State
{
  u8 tetrino_index; // which shape is it?
  s32 offset_row;   // current position
  s32 offset_col;
  s32 rotation; // current pose
};

struct Game_State
{
  u8 board[WIDTH * HEIGHT];
  Piece_State piece;
  Game_Phase phase;
};

inline u8
matrix_get(const u8 *values, s32 width, s32 row, s32 col)
{
  s32 index = row * width + col;
  return values[index];
}

inline void
matrix_set(u8 *values, s32 width, s32 row, s32 col, u8 value)
{
  s32 index = row * width + col;
  values[index] = value;
}

inline u8
tetrino_get(Tetrino *tetrino, s32 row, s32 col, s32 rotation)
{
  s32 side = tetrino->side;
  switch (rotation)
  {
  // no rotation
  case 0:
    return tetrino->data[row * side + col];
  // rotatation CW
  // row = -col'; col = row'
  case 1:
    return tetrino->data[(side - col - 1) * side + row];
  // two rotations CW
  // row = -row'; col = -col'
  case 2:
    return tetrino->data[(side - row - 1) * side + (side - col - 1)];
  // rotation CCW
  // row = col'; col = -row'
  case 3:
    return tetrino->data[col * side + (side - row - 1)];
  }
  // wrong rotation case
  return -1;
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