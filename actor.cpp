#include "actor.h"
//#include "ai.h"
//#include "feature.h"
//#include "featclass.h"
#include "globals.h"
#include "graphics.h"
//#include "load.h"
#include "map.h"
#include "object.h"
#include "objclass.h"
#include "tile.h"
//#include "tileclass.h"
#include "window.h"

#define SET_SYMBOL(O,S,C) O->img = S|C

actor::actor(short code){

	type = code;
		
	name = aclass[type].name;
	//new->aitype = aclass[code].ai;
	
	level = 1;
	maxHP = HP = 5;
	gold = 0;
	
	state = 0; //STATE_STAND;
	
}

chtype actor::get_img(){
	return comp(aclass[type].symbol, aclass[type].color);
}

std::string actor::get_name(){
	if(act_player == this)
		return "you";
	else
		return aclass[type].name;
}

void actor::move(std::pair<int,int> offset) {

	map_current->tiles[x][y].my_actor = NULL;
	
	x += offset.first;
	y += offset.second;
	
	map_current->tiles[x][y].my_actor = this;
}

void actor::attack(std::pair<int,int> offset) {
	tile * place;
	place = &map_current->tiles[x + offset.first][y + offset.second];
	attack(place->my_actor);
}

void actor::attack(actor * target){
	win_output->print(get_name() + std::string("-> attack ->") + target->get_name());
}