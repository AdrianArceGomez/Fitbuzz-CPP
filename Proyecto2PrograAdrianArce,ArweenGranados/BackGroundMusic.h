#pragma once
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>

class BackgroundMusic {
private:
	sf::Music music;

public:
	BackgroundMusic(const std::string& filePath);
	void play(bool loop = false);
	void pause();
	void stop();
	void setVolume(float volume);
};