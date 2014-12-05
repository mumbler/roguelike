#ifndef SYMBOLDEFS_H
#define SYMBOLDEFS_H

#include "config.h"

void define_symbols();

#if DISPLAY_TYPE == DISPLAY_CURSES || DISPLAY_TYPE == DISPLAY_WCURSES

enum character {
  // ASCII
  CHAR_a = 0,
  CHAR_b,
  CHAR_c,
  CHAR_d,
  CHAR_e,
  CHAR_f,
  CHAR_g,
  CHAR_h,
  CHAR_i,
  CHAR_j,
  CHAR_k,
  CHAR_l,
  CHAR_m,
  CHAR_n,
  CHAR_o,
  CHAR_p,
  CHAR_q,
  CHAR_r,
  CHAR_s,
  CHAR_t,
  CHAR_u,
  CHAR_v,
  CHAR_w,
  CHAR_x,
  CHAR_y,
  CHAR_z,
  CHAR_A,
  CHAR_B,
  CHAR_C,
  CHAR_D,
  CHAR_E,
  CHAR_F,
  CHAR_G,
  CHAR_H,
  CHAR_I,
  CHAR_J,
  CHAR_K,
  CHAR_L,
  CHAR_M,
  CHAR_N,
  CHAR_O,
  CHAR_P,
  CHAR_Q,
  CHAR_R,
  CHAR_S,
  CHAR_T,
  CHAR_U,
  CHAR_V,
  CHAR_W,
  CHAR_X,
  CHAR_Y,
  CHAR_Z,
  CHAR_0,
  CHAR_1,
  CHAR_2,
  CHAR_3,
  CHAR_4,
  CHAR_5,
  CHAR_6,
  CHAR_7,
  CHAR_8,
  CHAR_9,
  CHAR_SPACE,
  CHAR_AT,
  CHAR_PLUS,
  CHAR_EQUAL,
  CHAR_DASH,
  CHAR_UNDERSCORE,
  CHAR_FSLASH,
  CHAR_BSLASH,
  CHAR_PIPE,
  CHAR_OPAREN,
  CHAR_CPAREN,
  CHAR_OBRACE,
  CHAR_CBRACE,
  CHAR_OSQBRACKET,
  CHAR_CSQBRACKET,
  CHAR_OANBRACKET,
  CHAR_CANBRACKET,
  CHAR_PERIOD,
  CHAR_COMMA,
  CHAR_APOSTROPHE,
  CHAR_SEMICOLON,
  CHAR_COLON,
  CHAR_QUOTE,
  CHAR_QMARK,
  CHAR_ASTER,
  CHAR_AMPERS,
  CHAR_CARAT,
  CHAR_PERCENT,
  CHAR_DOLLAR,
  CHAR_HASH,
  CHAR_EXCLAIM,
  CHAR_TILDE,
  // extended
  CHAR_DOT,
  CHAR_LSHADE,
  CHAR_MSHADE,
  CHAR_DSHADE,
  CHAR_FILLED,
  CHAR_MAX
};

enum symbol {
  SYM_PLAYER = CHAR_AT,
  SYM_FOOD = CHAR_PERCENT,
  SYM_MONEY = CHAR_DOLLAR,
  SYM_WEAPON = CHAR_OPAREN,
  SYM_ARMOR = CHAR_OSQBRACKET,
  SYM_MONSTER = CHAR_M,
  SYM_ROBOT = CHAR_R,
  SYM_WALL = CHAR_SPACE,
  SYM_FLOOR = CHAR_DOT,
  SYM_GRASS = CHAR_QUOTE,
  SYM_WATER = CHAR_TILDE
};
#endif

symbol_code get_symbol(character);

#endif