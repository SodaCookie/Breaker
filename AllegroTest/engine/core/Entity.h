#ifndef ENTITY_H
#define ENTITY_H

#include "Handle.h"
#include "Component.h"
#include <algorithm>
#include <vector>
#include <memory>

class Entity
{
	private:
		const Handle id;
		std::vector<Handle> components;

	public:
		Entity(Handle id);
		~Entity();

		std::vector<Handle> get_component_handles();
		void add_component(const Handle id);
		bool has_component(const Handle id);
};

#endif