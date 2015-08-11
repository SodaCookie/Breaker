#ifndef OBJECT_MANAGER_H
#define OBJECT_MANAGER_H

#include "Handle.h"
#include "Component.h"
#include "Entity.h"
#include "System.h"
#include <deque>
#include <map>
#include <tuple>
#include <memory>
#include <string>

class ObjectManager
{
	private:
		std::vector<Entity> entities;
		std::map<SystemType, std::deque<int>> empties;

	public:
		ObjectManager();
		~ObjectManager();

		bool register_system(std::shared_ptr<System> system);
		std::shared_ptr<Component> create_component(std::shared_ptr<System> system, std::shared_ptr<void> data); // Create component for an entity
		std::shared_ptr<Entity> create_entity(std::vector<Component> components); // Create an entity from a list on components

		bool delete_entity(const Handle handle);
		bool delete_component(const Handle handle);

		std::shared_ptr<Entity> get_entity(Handle handle);
		std::vector<std::shared_ptr<Component>> get_components(SystemType type);
		std::deque<std::shared_ptr<Entity>> get_objects();
};

extern const SystemType ObjectSystemType;

#endif