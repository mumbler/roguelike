#ifndef ARGMAP_H

#define ARGMAP_H

#include "enums.h"
#include "globals.h"
#include <map>
#include <vector>

enum args_t {
    ARG_HOLDER_ENTITY = 0, // ===== TRIGGER CARRIERS =======
    ARG_HOLDER_ACTOR,
    ARG_HOLDER_OBJECT,
    ARG_HOLDER_FEATURE,
    ARG_HOLDER_CONDITION,
    ARG_ACTION_AGENT, // ===== ACTION ROLES =======
    ARG_ACTION_PATIENT,
    ARG_ACTION_INSTRUMENT,
    ARG_ACTION_LOCATION,
    ARG_FEAT_CLOSEDSTATE, // ===== FEATURE STATES =======
    ARG_FEAT_OPENSTATE,
    ARG_EFFECT_RADIUS, // ===== EFFECTS =======
    ARG_TARGET_ENTITY_TYPE, // ===== TARGETING =======
    ARG_TARGET_NUMBER, // Max number that can be chosen
    ARG_TARGET_DISTANCE, // Distance from agent
    ARG_TARGET_GOLDOK, // Can gold be chosen from inventory
    ARG_TARGET_ASSUME, // Automatically choose all if this many or fewer
    ARG_REQUIRE_STAT, // ===== REQUIREMENTS =======
    ARG_REQUIRE_FLAG,
    ARG_REQUIRE_VALUE,
    ARG_REQUIRE_PATIENT
};

/*
    For now states will share a map with stats. Starting them at a high value so
    there's no overlap. Should probably change this later.
*/
enum state_t {

    STATE_FEAT_OPEN = 1000,
    STATE_FEAT_CLOSED
};

using std::vector;

class entity;
class entityclass;
class feature;
class tile;
class condition;

class argmap {

	private:
    std::map<int, void *> * the_map;

	public:
	argmap();
    argmap(argmap *);
	bool add_int(args_t, int);
    bool add_entity(args_t, entity *);
	bool add_actor(args_t, actor *);
	bool add_object(args_t, object *);
    bool add_feature(args_t, feature *);
    bool add_tile(args_t, tile *);
    bool add_condition(args_t, condition *);
	bool add_vector(args_t, vector<void*> *);
    
	bool has_value(args_t);
	int get_int(args_t);
    entity * get_entity(args_t);
	actor * get_actor(args_t);
	object * get_object(args_t);
	feature * get_feature(args_t);
	tile * get_tile(args_t);
    condition * get_condition(args_t);
	vector<void*> * get_vector(args_t);
    
	void add_args(argmap *);
	void add_args(argmap *, bool);
	
	// Stat functions
	bool add_stat(stats_t, int);
	int get_stat(stats_t);
	bool has_stat(stats_t);
    
    // State functions
    bool add_state(state_t, entityclass *);
    entityclass * get_state(state_t);
    bool has_state(state_t);
};

typedef argmap statmap;

#endif
