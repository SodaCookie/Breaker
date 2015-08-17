#ifndef EVENTSYSTEM_H
#define EVENTSYSTEM_H

#include "engine/core/System.h"
#include "engine/core/SystemType.h"
#include "engine/core/Component.h"
#include "allegro5/allegro.h"
#include <memory>
#include <vector>
#include <map>

extern const SystemType EventSystemType;

class EventSystem : public System
{
	private:
		ALLEGRO_EVENT_QUEUE *queue;

	public:
		EventSystem();
		~EventSystem();

		INITSTATUS init();
		void quit();
		SYSTEMSTATUS update(std::vector<std::shared_ptr<Component>> components, double dtime);

		void register_source(ALLEGRO_EVENT_SOURCE *source);
		//void handle();
		//void sub(std::shared_ptr<Component>);
		//void unsub();
		
};

#endif