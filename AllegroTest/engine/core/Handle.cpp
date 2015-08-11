#include "Handle.h"

bool operator==(const Handle &lhs, const Handle &rhs){
	return (lhs.type == rhs.type) && (lhs.key == rhs.key);
}