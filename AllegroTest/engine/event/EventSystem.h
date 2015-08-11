#ifndef EVENTSYSTEM_H
#define EVENTSYSTEM_H

#include "engine/core/System.h"
#include "allegro5/allegro.h"
#include <memory>
#include <vector>
#include <map>

class EventSystem : public System
{
	private:
		ALLEGRO_EVENT_QUEUE *queue;

	public:
		EventSystem();
		~EventSystem();

		bool init();
		void quit();
		int update(std::vector<std::shared_ptr<Component>> components, double dtime);

		//void handle();
		//void sub();
		//void unsub();
		
};

#endif