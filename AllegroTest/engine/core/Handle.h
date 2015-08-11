#ifndef HANDLE_H
#define HANDLE_H

#include "SystemType.h"

class Handle{
	public:

		Handle(SystemType type, int key) : type(type), key(key) { }

		const SystemType type;
		const unsigned int key;
};

extern bool operator==(const Handle &lhs, const Handle &rhs);

#endif