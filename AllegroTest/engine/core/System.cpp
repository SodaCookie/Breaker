#include "System.h"

System::System(SystemType type) : type(type){
}

std::string System::error(){
	return "ERROR: " + error_msg;
}

std::shared_ptr<Component> System::create_component(Handle id, std::shared_ptr<void> data){
	std::shared_ptr<Component> component = std::make_shared<Component>(Component(id));
	return component;
}


std::shared_ptr<Component> System::get_component(Handle id){
	return GAME_OBJECTS.components[id.type][id.key];
}

SystemType System::get_type(){
	return type;
}

void System::set_error_msg(std::string msg){
	error_msg = msg;
}	