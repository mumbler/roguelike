#ifndef ARGMAP_H

#define ARGMAP_H

#include "enums.h"

#include <map>
#include <set>
#include <vector>

class actor;
class feature;
class object;
class tile;

enum args_t {
    ARG_NONE = -1,
    ARG_HOLDER_ENTITY, // ===== TRIGGER CARRIERS =======
    ARG_HOLDER_ACTOR,
    ARG_HOLDER_OBJECT,
    ARG_HOLDER_FEATURE,
    ARG_HOLDER_CONDITION,
    ARG_ACTION_AGENT, // ===== ACTION ROLES ======= - Returned by targeting, sent to blocks (ACTROLE is what is stored in the execute function, used by extract)
    ARG_ACTION_PATIENT,
    ARG_ACTION_INSTRUMENT,
    ARG_ACTION_LOCATION,
    ARG_ACTION_TARGET_ROLE, // The role slot to put the target (the entity weighed by the AI routine) into,
    ARG_FEAT_CLOSEDSTATE, // ===== FEATURE STATES =======
    ARG_FEAT_OPENSTATE,
    ARG_EFFECT_RADIUS, // ===== EFFECTS =======
    ARG_TARGET_ENTITY_TYPE, // ===== TARGETING =======
    ARG_TARGET_NUMBER, // Max number that can be chosen
    ARG_TARGET_MAX_DISTANCE, // Distance from agent
    ARG_TARGET_MIN_DISTANCE,
    ARG_TARGET_ASSUME, // Automatically choose all if this many or fewer
    ARG_REQUIRE_STAT, // ===== REQUIREMENTS =======
    ARG_REQUIRE_FLAG,
    ARG_REQUIRE_VALUE,
    ARG_REQUIRE_PRIMARY,
    ARG_REQUIRE_SECONDARY,
    ARG_REQUIRE_PARTIAL_TYPE,
    ARG_AI_TARG_TYPE, // ============= AI ANNOTATION ================
    ARG_AI_MOVE_TYPE,
    ARG_AI_MIN_DISTANCE, 
    ARG_AI_MAX_DISTANCE,
    ARG_AI_REQUIRE_EQUIPPED_SLOT, // Takes equip slot
    ARG_AI_REQUIRE_EQUIP_TYPE, // Takes object type
    ARG_AI_REQUIRE_EQUIP_SUBTYPE, // Takes object subtype
    ARG_FLAGS // ========== MISCELLANEOUS ================
};

enum flags_t {
    FLAG_NULL = 0,
    FLAG_ACT_CAN_WALK,
    FLAG_ACT_CAN_SWIM,
    FLAG_ACT_CAN_FLY,
    FLAG_ACT_OPAQUE,
    FLAG_OBJ_IN_INVENTORY, // OBJECTS ===========
    FLAG_TILE_CAN_WALK, // TILES ==============
    FLAG_TILE_CAN_SWIM,
    FLAG_TILE_CAN_FLY,
    FLAG_TILE_OPAQUE,
    FLAG_FEAT_NO_WALK, // FEATURES ==============
    FLAG_FEAT_NO_SWIM,
    FLAG_FEAT_NO_FLY,
    FLAG_FEAT_CAN_OPEN,
    FLAG_FEAT_CAN_CLOSE,
    FLAG_FEAT_OPAQUE,
    FLAG_ACTION_WALK, // ACTIONS ===================
    FLAG_ACTION_SWIM,
    FLAG_ACTION_FLY,
    FLAG_TARGET_NOT_SELF, // Targeting ------------ 
    FLAG_TARGET_SELF_ONLY,
    FLAG_TARGET_GOLDOK, // Can gold be chosen from inventory
    FLAG_REQ_NEGATED, // Requirements ---------------------
    FLAG_MENU_SORT, // MENUS ==============
    FLAG_MENU_PLAYER,
    FLAG_TARGET_BREAK_PROJECTILE // Target options =========
};

/*
    For now states will share a map with stats. Starting them at a high value so
    there's no overlap. Should probably change this later.
*/
enum state_t {

    STATE_FEAT_OPEN = 1000,
    STATE_FEAT_CLOSED
};

using std::set;
using std::vector;

class action;
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
    bool add_action(args_t, action *);
	bool add_vector(args_t, vector<void*> *);
    bool add_set(args_t, set<void*> *);
    
	bool has_value(args_t);
	int get_int(args_t);
    entity * get_entity(args_t);
	actor * get_actor(args_t);
	object * get_object(args_t);
	feature * get_feature(args_t);
	tile * get_tile(args_t);
    condition * get_condition(args_t);
    action * get_action(args_t);
	vector<void*> * get_vector(args_t);
    set<void*> * get_set(args_t);
    
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
    
    // Flag functions
    bool add_flag(flags_t);
    bool remove_flag(flags_t);
    bool has_flag(flags_t);
    
    // Various helpers
    bool add_into_vector(args_t, entity*);
    entity * get_from_vector(args_t);
};

typedef argmap statmap;

#endif
