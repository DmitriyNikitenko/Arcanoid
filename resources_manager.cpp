#include <iostream>
#include "include/resources_manager.h"

sf::Font& Resources_Manager::getFont(const std::string& path) {
	const auto& pair_found = fonts.find(path);

	if (pair_found != fonts.end()) {
		return pair_found->second;
	}
	else {
		auto& font = fonts[path];
		if (!font.openFromFile(path)) {
			std::cerr << "ERROR: Unable to load texture\n";
			exit(1);
		}
		return font;
	}
}


sf::Texture& Resources_Manager::getTexture(const std::string& path) {
	const auto& pair_found = textures.find(path);

	if (pair_found != textures.end()) {
		return pair_found->second;
	}
	else {
		auto& texture = textures[path];
		if (!texture.loadFromFile(path)) {
			std::cerr << "ERROR: Unable to load texture\n";
			exit(1);
		}
		return texture;
	}

}


sf::SoundBuffer& Resources_Manager::getSound(const std::string& path) {
	const auto& pair_found = sounds.find(path);

	if (pair_found != sounds.end()) {
		return pair_found->second;
	}
	else {
		auto& sound = sounds[path];
		if (!sound.loadFromFile(path)) {
			std::cerr << "ERROR: Unable to load texture\n";
			exit(1);
		}
		return sound;
	}

}
