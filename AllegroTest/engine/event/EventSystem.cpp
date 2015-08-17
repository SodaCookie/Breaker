#include "engine/event/EventSystem.h"
#include <iostream>

const SystemType EventSystemType = map_system_type(0, 0, 0, 3);

EventSystem::EventSystem() : System(EventSystemType)
{
}


EventSystem::~EventSystem()
{
}

void EventSystem::register_source(ALLEGRO_EVENT_SOURCE *source){
	al_register_event_source(queue, source);
}

INITSTATUS EventSystem::init(){
	queue = al_create_event_queue();
	if (!queue){
		set_error_msg("Event queue failed to initialize");
		return INITFAILURE;
	}
	return INITSUCCESS;
}

void EventSystem::quit(){
	al_destroy_event_queue(queue);
}

SYSTEMSTATUS EventSystem::update(std::vector<std::shared_ptr<Component>> components, double dtime){
	ALLEGRO_EVENT event;
	while (al_get_next_event(queue, &event)){
		std::cout << "EVENT\n";
		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
			return SYSTEMEXIT;
		}
	}
	return SYSTEMNORMAL;
}