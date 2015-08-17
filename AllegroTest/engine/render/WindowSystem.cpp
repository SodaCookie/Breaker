#include "WindowSystem.h"

const SystemType WindowSystemType = map_system_type(0, 0, 0, 2);

WindowSystem::WindowSystem(int width, int height) : System(WindowSystemType), 
width(width), height(height){
}

WindowSystem::~WindowSystem(){
}

ALLEGRO_EVENT_SOURCE *WindowSystem::get_event_source(){
	return al_get_display_event_source(window);
}

INITSTATUS WindowSystem::init(){
	window = al_create_display(width, height);
	
	if (!window){
		set_error_msg("Failed to create display\n");
		return INITFAILURE;
	}

	return INITSUCCESS;
}

void WindowSystem::quit(){
	al_destroy_display(window);
}

SYSTEMSTATUS WindowSystem::update(std::vector<std::shared_ptr<Component>> components, double dtime){
	return SYSTEMNORMAL;
}