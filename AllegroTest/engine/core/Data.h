/*Data header file is used to define a general struct that holds
pointers to entities in the game and a map of system identifier
to its components. It also defines constant GAME_OBJECT which is
a global object to track a game's data. This should only be handled
by the object manager, base entity and systems.*/

#ifndef DATA_H
#define DATA_H

#include "Handle.h"
#include "Component.h"
#include "Entity.h"
#include <string>
#include <memory>
#include <deque>
#include <map>

typedef struct{
	std::deque<std::shared_ptr<Entity>> entities;
	std::map<SystemType, std::vector<std::shared_ptr<Component>>> components;
} GameContainer;

extern GameContainer GAME_OBJECTS;

#endif