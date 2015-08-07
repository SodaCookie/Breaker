#ifndef HANDLE_H
#define HANDLE_H

#include <string>

class Handle{
	public:
		Handle(std::string type, int key) : type(type), key(key) { }
		std::string type;
		int key;
};

#endif