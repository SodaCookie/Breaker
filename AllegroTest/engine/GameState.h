#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Block.h"
#include <utility>
#include <vector>

class GameState{

	public:
		GameState();
		~GameState();

		std::pair<int, int> ball_coord;
		std::pair<int, int> ball_vel;
		int player_coord;
		std::vector<Block> blocks
};

#endif