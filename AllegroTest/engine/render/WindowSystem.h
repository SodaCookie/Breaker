#ifndef WINDOW_SYSTEM_H
#define WINDOW_SYSTEM_H

#include "engine/core/SystemType.h"
#include "engine/core/System.h"
#include "allegro5/allegro.h"
#include <memory>

extern const SystemType WindowSystemType;

class WindowSystem : public System
{
	private:
		ALLEGRO_DISPLAY *window;
		int width;
		int height;

	public:
		WindowSystem(int width, int height);
		~WindowSystem();

		INITSTATUS init();
		void quit();
		SYSTEMSTATUS update(std::vector<std::shared_ptr<Component>> components, double dtime);
		ALLEGRO_EVENT_SOURCE *get_event_source();
};

#endif