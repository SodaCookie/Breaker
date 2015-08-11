#include "ObjectManager.h"

const SystemType ObjectSystemType = map_system_type(0, 0, 0, 0);

ObjectManager::ObjectManager(){
	empties[ObjectSystemType] = std::deque<int>();
}


ObjectManager::~ObjectManager(){
}

std::shared_ptr<Component> ObjectManager::create_component(std::shared_ptr<System> system, std::shared_ptr<void> data){
	int location;
	std::shared_ptr<Component> component = 0;
	if (empties[system->get_type()].size()){ // If there is an empty space detected
		location = empties[system->get_type()].front();
		empties[system->get_type()].pop_front();

		const Handle handle(system->get_type(), location);
		component = system->create_component(handle, data);
		GAME_OBJECTS.components[system->get_type()][location] = component;
	}
	else {
		const Handle handle(system->get_type(), GAME_OBJECTS.entities.size());
		component = system->create_component(handle, data);
		GAME_OBJECTS.components[system->get_type()].push_back(component);
	}
	return component;

}

std::shared_ptr<Entity> ObjectManager::create_entity(std::vector<Component> components){
	int location;
	std::shared_ptr<Entity> entity = 0;
	if (empties[ObjectSystemType].size()){ // If there is an empty space detected
		location = empties[ObjectSystemType].front();
		empties[ObjectSystemType].pop_front();
		
		const Handle handle(ObjectSystemType, location);
		entity = std::make_shared<Entity>(Entity(handle));
		GAME_OBJECTS.entities[location] = entity;
	}
	else { // else we append a new Entity and permanently increase size by one
		const Handle handle(ObjectSystemType, GAME_OBJECTS.entities.size());
		entity = std::make_shared<Entity>(Entity(handle));
		GAME_OBJECTS.entities.push_back(entity);
	}
	return entity;

}

bool ObjectManager::delete_entity(const Handle handle){
	std::shared_ptr<Entity> entity = 0;
	if (handle.type == ObjectSystemType){
		GAME_OBJECTS.entities[handle.key] = entity;
		empties[ObjectSystemType].push_back(handle.key);
		return true;
	}
	else {
		return false;
	}
}

bool ObjectManager::delete_component(const Handle handle){
	std::shared_ptr<Component> component = 0;
	GAME_OBJECTS.components[handle.type][handle.key] = component;
	empties[handle.type].push_back(handle.key);
	return true;
}

std::shared_ptr<Entity> ObjectManager::get_entity(const Handle handle){
	std::shared_ptr<Entity> entity = 0;
	if (handle.type == ObjectSystemType){
		entity = GAME_OBJECTS.entities[handle.key];
	}
	return entity;
}

std::vector<std::shared_ptr<Component>> ObjectManager::get_components(SystemType type){
	return GAME_OBJECTS.components[type];
}

std::deque<std::shared_ptr<Entity>> ObjectManager::get_objects(){
	return GAME_OBJECTS.entities;
}

bool ObjectManager::register_system(std::shared_ptr<System> system){
	for (auto &items : empties){
		if (items.first == system->get_type()){ // found type in empties
			return false;
		}
	}
	empties[system->get_type()] = std::deque<int>();
	GAME_OBJECTS.components[system->get_type()] = std::vector<std::shared_ptr<Component>>();
	return true;
}