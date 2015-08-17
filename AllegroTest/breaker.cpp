#include "engine/engine.h"
#include <iostream>
#include <memory>
#include <allegro5/allegro.h>

int main(int argc, char **argv)
{
	Engine engine;
	std::shared_ptr<AllegroSystem> allegro_system(new AllegroSystem());
	std::shared_ptr<WindowSystem> window_system(new WindowSystem(800, 600));
	std::shared_ptr<EventSystem> event_system(new EventSystem());

	engine.add_system(allegro_system);
	engine.add_system(window_system);
	engine.add_system(event_system);

	engine.init();
	if (!engine.was_init()){
		return 0;
	}

	event_system->register_source(window_system->get_event_source());

	engine.main_loop();
	engine.quit();
}