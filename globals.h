#ifndef GLOBALS_H

#define GLOBALS_H

#include "actclass.h"
#include "actor.h"
#include "objclass.h"
//#include "map.h"
#include "window.h"
#include "tileclass.h"

#define MAX_INVENTORY 48

/*
int map_id = 1;
object *letter[53];
*/

// Windows
extern window * win_output;
extern window * win_world;
extern window * win_status;
extern window * win_screen;

extern buffer * buf_main;

// Current map and player
extern map * map_current;
extern actor * act_player;

// Player's item letter assignments
//extern object * letter[];

//Position of game window on map
extern short scrn_x, scrn_y;
extern short term_w, term_h;

// Global counters
extern int map_id;
extern int turn;

// Object class arrays
extern actclass aclass[];
extern objclass oclass[];
extern struct tileclass tclass[];

// Color setup
extern int color_value[];

// Functions of general use
void redraw_windows();

#endif
