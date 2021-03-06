#ifndef AI_H
#define AI_H

#include "action.h"
#include "entity.h"

#include <map>
#include <vector>

using std::vector;

class entity;
class requirement;

class motivator {

    public:
    bool self;
    requirement * req;
    int value;

    motivator(bool, requirement *, int);
};

class idea {

    public:
    entity_type e_type;
    actionPurpose_t purpose;
    int base;
    vector<motivator*> * motivators;
    
    idea(entity_type, actionPurpose_t, int);
};

class aimodule {

    public:
    std::map<entity_type, vector<idea*>* > * ideas;
    
    void add_idea(idea *);
    aimodule();
};

class goal {

    public:
    entity * target;
    actionPurpose_t purpose;
    
    goal(entity *, actionPurpose_t);
};

class mind {

    public:
    aimodule * module;
    goal * cur_goal;
    
    mind(aimodule *);
};

class consider_resp {

    public:
    actionPurpose_t main_purpose;
    actionPurpose_t sub_purpose;
    entity * main_target;
    entity * sub_target;
    action * ac; // The action I'd use
    int desire; // The attraction with effort included
    
    consider_resp(actionPurpose_t, entity *, action *, int);
    consider_resp(actionPurpose_t, actionPurpose_t, entity *, entity *, action *, int);
};

class best_act_resp {

    public:
    actionPurpose_t purpose;
    action * ac;
    entity * target;
    int effort;
    
    best_act_resp(actionPurpose_t, action *, entity *, int);
};

class AI {

    public:
    static vector<entity*> * sense_entities(actor*);
    static consider_resp * consider_turn(actor *);
    static int idea_value(actor *, entity *, idea *);
    static best_act_resp * choose_action(actionPurpose_t, actor *, entity *);
    static goal * goal_to_solve(actor * act, goal * g, error * err);
    
    static int take_action(actor*, consider_resp *);
};

extern aimodule * aimod[];

#endif
