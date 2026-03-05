#pragma once
#include "resources_manager.h"
#include "block.h"
#include <unordered_map>
#include <vector>
#include <string>

class LevelsManager {
private:
	Resources_Manager& resources;
	const std::unordered_map<char, BlockColor> color_maping{
		{'O', BlockColor::orange} ,{'R', BlockColor::red},
		{'G', BlockColor::green},{'B', BlockColor::blue},
		{'p', BlockColor::pink},{'C', BlockColor::cyan},
		{'Y', BlockColor::yellow},{'M', BlockColor::magenta}
	};
	std::vector<std::unique_ptr<Block>> blocks;
	std::vector<std::string> levels_data;

public:
	LevelsManager(Resources_Manager& resources);
	void loadLevel(unsigned int level_index);
	std::size_t levelAmount() const;
	friend class Game;
};