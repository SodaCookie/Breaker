#ifndef BLOCK_H
#define BLOCK_H

#include "allegro5/allegro.h"
#include "allegro5/allegro_primitives.h"
#include <utility>

class Block{
	private:
		ALLEGRO_COLOR color;
		std::pair<int, int> coord;
		std::pair<int, int> size;

	public:	
		Block(std::pair<int, int> coord, std::pair<int, int> size, ALLEGRO_COLOR colour);
		~Block();

		void render(ALLEGRO_BITMAP *bitmap, std::pair<int, int>coord);
};

#endif