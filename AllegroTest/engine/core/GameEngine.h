#ifndef ENGINE_H
#define ENGINE_H

#include "engine/core/Data.h"
#include "engine/core/System.h"
#include "engine/core/ObjectManager.h"
#include "allegro5/allegro.h"
#include <memory>
#include <vector>
#include <iostream>

class Engine
{
	private:
		double time;
		bool running;
		bool _was_init;
		std::vector<std::shared_ptr<System>> systems;

	public:
		Engine();
		~Engine() = default;

		ObjectManager object_manager;

		void init();
		bool was_init();
		void quit();

		void update(double dtime);
		void main_loop();
		bool add_system(std::shared_ptr<System> system);
};

#endif