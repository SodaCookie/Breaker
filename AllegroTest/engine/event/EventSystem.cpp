#include "engine/event/EventSystem.h"

EventSystem::EventSystem()
{
}


EventSystem::~EventSystem()
{
	al_destroy_event_queue(queue);
}

bool EventSystem::init(){

}

void EventSystem::quit(){

}

int EventSystem::update(std::vector<std::shared_ptr<Component>> components, double dtime){
	ALLEGRO_EVENT event;
	while (al_get_next_event(queue, &event)){
		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
			return SYSTEMEXIT;
		}
	}
	return SYSTEMNORMAL;
}