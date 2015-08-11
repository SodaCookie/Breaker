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

		bool init();
		void quit();
		int update(std::vector<std::shared_ptr<Component>> components, double dtime);
		std::shared_ptr<Component> create_component(std::shared_ptr<void> data);
};

#endif