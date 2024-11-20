#include "BackGroundMusic.h"



BackgroundMusic::BackgroundMusic(const std::string& filePath) {
    if (!music.openFromFile(filePath)) {
        std::cout << "Error al cargar la música desde: " << filePath << std::endl;
    }
}

void BackgroundMusic::play(bool loop) {
    music.setLoop(loop);
    music.play();
}

void BackgroundMusic::pause() {
    music.pause();
}

void BackgroundMusic::stop() {
    music.stop();
}

void BackgroundMusic::setVolume(float volume) {
    music.setVolume(volume);
}