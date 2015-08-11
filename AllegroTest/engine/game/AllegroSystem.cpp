#include "AllegroSystem.h"

const SystemType AllegroSystemType = map_system_type(0, 0, 0, 1);

AllegroSystem::AllegroSystem() : System(AllegroSystemType)
{
}

AllegroSystem::~AllegroSystem()
{
}

bool AllegroSystem::init(){
	if (!al_init()){
		set_error_msg("Could not initiate Allegro");
		return false;
	}
	return true;
}

void AllegroSystem::quit(){
}

int AllegroSystem::update(std::vector<std::shared_ptr<Component>> components, double dtime){
	return 0;
}
