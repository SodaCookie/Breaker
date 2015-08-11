#include "SystemType.h"

bool operator==(const SystemType &lhs, const SystemType &rhs){
	return (lhs.a == rhs.a) && (lhs.b == rhs.b) && (lhs.c == rhs.c) && (lhs.d == rhs.d);
}

bool operator<(const SystemType &lhs, const SystemType &rhs){
	if (lhs.a > rhs.a){
		return false;
	}
	else if (lhs.b > rhs.b){
		return false;
	}
	else if (lhs.c > rhs.c){
		return false;
	}
	else if (lhs.d >= rhs.d){
		return false;
	}
	return true;
}

const SystemType map_system_type(unsigned int a, unsigned int b, unsigned int c, unsigned int d){
	SystemType type(a, b, c, d);
	return type;
}