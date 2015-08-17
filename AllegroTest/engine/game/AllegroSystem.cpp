#include "AllegroSystem.h"

const SystemType AllegroSystemType = map_system_type(0, 0, 0, 1);

AllegroSystem::AllegroSystem() : System(AllegroSystemType)
{
}

AllegroSystem::~AllegroSystem()
{
}

INITSTATUS AllegroSystem::init(){
	if (!al_init()){
		set_error_msg("Could not initiate Allegro");
		return INITFAILURE;
	}
	return INITSUCCESS;
}

void AllegroSystem::quit(){
}

SYSTEMSTATUS AllegroSystem::update(std::vector<std::shared_ptr<Component>> components, double dtime){
	return SYSTEMNORMAL;
}
