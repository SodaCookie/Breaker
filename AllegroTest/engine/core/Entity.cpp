#include "Entity.h"


Entity::Entity(const Handle id) : id(id){ // potential for badness
}


Entity::~Entity() {
}

std::vector<Handle> Entity::get_component_handles(){
	return components;
}

void Entity::add_component(const Handle id){
	if (!this->has_component(id)){
		components.push_back(id);
	}
}

bool Entity::has_component(const Handle id){
	return std::find(components.begin(), components.end(), id) != components.end();
}