#include "include/levels_manager.h"
#include <fstream>
#include <iostream>

LevelsManager::LevelsManager(Resources_Manager& resources):
	resources(resources)
{
	std::ifstream levelInput("resources\\levels.txt");

	if (!levelInput) {
		std::cerr << "Cannot read 'resources\\levels.txt' data \n";
		exit(EXIT_FAILURE);
	}
	std::string level;
	std::string buffer;

	while (!levelInput.eof()) {
		std::getline(levelInput, buffer);
		if (buffer.at(0) != '#') {
			level += buffer;
		}
		else {
			if (!level.empty()) {
				levels_data.emplace_back(level);
				level.clear();
			}
		}
	}
	levelInput.close();
}

void LevelsManager::loadLevel(unsigned int level_index) {
	blocks.clear();
	blocks.reserve(80);
	/*  Сохдание блоков  */
	float pos_x{ Block::width / 2 };
	float pos_y{ 2 * Block::height };

	std::size_t counter_new_line = 0;
	for (const char ch : levels_data.at(level_index)) {
		if (ch != '.') {
			blocks.emplace_back(
				std::make_unique<Block>(resources, color_maping.at(ch), sf::Vector2f({pos_x, pos_y}) )
			);
		}
		++counter_new_line;
		if (counter_new_line == 10) {
			pos_x = Block::width / 2;
			pos_y += Block::height;
			counter_new_line = 0;;
		}
		else {
			pos_x += Block::width;

		}
	}

}

std::size_t LevelsManager::levelAmount() const {
	return levels_data.size();
}
