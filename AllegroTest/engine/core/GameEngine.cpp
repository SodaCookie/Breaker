#include "GameEngine.h"

Engine::Engine()
{
	running = true;
	_was_init = false;
}

void Engine::init(){
	/*Calls all systems' init methods. If any method returns 
	false then an error occured and the error will be printed out*/
	for (std::shared_ptr<System> &system : systems){
		if (!system->init()){
			std::cout << system->error() << std::endl;
			return;
		}
	}
	_was_init = true;
	time = al_get_time();
}

void Engine::quit(){
	/*Calls all Systems' quit methods*/
	for (auto system = systems.rbegin(); system != systems.rend(); system++){
		(*system)->quit();
	}
}

bool Engine::was_init(){
	return _was_init;
}

void Engine::update(double dtime){
	int status;
	for (std::shared_ptr<System> &system : systems){
		status = system->update(object_manager.get_components(system->get_type()), dtime); // < 0 is error, 0 is all is good, > 0 is exit nicely
		if (status){
			if (status < 0){
				std::cout << system->error() << std::endl; // Basic for now might eventually add error types
			}
			running = false;
			break;
		}
	}
}

void Engine::main_loop(){
	/*Holds the main loop of the game. When running is set to false than 
	the game loop stops*/
	while (running){
		this->update(time-al_get_time());
		time = al_get_time();
	}
}

bool Engine::add_system(std::shared_ptr<System> system){
	/*add_system takes a System shared_ptr and returns a bool.
	If the another system in Engine shares the same name as the
	added system then false is returned and the system is not added.
	If true is returned than the system has been added to Engine*/
	for (std::shared_ptr<System> &cur_system : systems){
		if (cur_system->get_type() == system->get_type()){
			return false; // System exists
		}
	}
	systems.push_back(system); // add ssytem
	object_manager.register_system(system);
	return true;
}