#include "engine/event/EventSystem.h"

EventSystem::EventSystem(std::shared_ptr<ALLEGRO_EVENT_QUEUE> queue) :
queue(queue)
{
}


EventSystem::~EventSystem()
{
	al_destroy_event_queue(queue.get());
}

void EventSystem::handle(){
	ALLEGRO_EVENT event;
	while (al_get_next_event(queue.get(), &event)){
		
	}
}