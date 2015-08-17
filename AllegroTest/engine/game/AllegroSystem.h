#ifndef ALLEGRO_SYSTEM_H
#define ALLEGRO_SYSTEM_H

#include "engine/core/System.h"
#include "engine/core/SystemType.h"
#include "allegro5/allegro.h"

extern const SystemType AllegroSystemType;

class AllegroSystem : public System
{
	public:
		AllegroSystem();
		~AllegroSystem();

		INITSTATUS init();
		void quit();
		SYSTEMSTATUS update(std::vector<std::shared_ptr<Component>> components, double dtime);
};

#endif