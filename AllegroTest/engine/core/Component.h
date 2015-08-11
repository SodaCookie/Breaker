#ifndef COMPONENT_H
#define COMPONENT_H

#include "Handle.h"

class Component
{
private:
	Handle id;

public:
	Component(Handle id);
	~Component();
};

#endif