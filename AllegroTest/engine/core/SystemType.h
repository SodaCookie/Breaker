#ifndef SYSTEM_TYPE_H
#define SYSTEM_TYPE_H

typedef struct SystemType{
	const unsigned int a;
	const unsigned int b;
	const unsigned int c;
	const unsigned int d;

	SystemType(unsigned int a, unsigned int b, unsigned int c, unsigned int d) :
		a(a), b(b), c(c), d(d){
	}

} SystemType;

extern bool operator==(const SystemType &lhs, const SystemType &rhs);

extern bool operator<(const SystemType &lhs, const SystemType &rhs);

extern const SystemType map_system_type(unsigned int a, unsigned int b, unsigned int c, unsigned int d);

#endif // !SYSTEM_TYPE_H
