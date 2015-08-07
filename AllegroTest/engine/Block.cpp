#include "Block.h"

Block::Block(std::pair<int, int> coord, std::pair<int, int> size, ALLEGRO_COLOR color) : 
coord(coord), size(size), color(color)
{
}

Block::~Block(){
}

void Block::render(ALLEGRO_BITMAP *bitmap, std::pair<int, int>coord){
	al_set_target_bitmap(bitmap);
	al_draw_filled_rectangle(coord.first, coord.second, size.first, size.second, color);
}