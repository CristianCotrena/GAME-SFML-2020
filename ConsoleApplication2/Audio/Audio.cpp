#include <SFML/Audio.hpp>
#include "Audio.h"

Audio::Audio() {
	press = false;
	explosion.loadFromFile("explosion.wav");
};

void loadSound(int i, sf::SoundBuffer& buffer, sf::Sound& sound){	
	switch (i) {
		case 1:
			buffer.loadFromFile("a.wav");
			break;
		case 2:
			buffer.loadFromFile("tiro.wav");
			break;
		case 3:
			buffer.loadFromFile("aviaoInicio.wav");
			break;
		case 4:
			buffer.loadFromFile("explosion.wav");
			break;
		case 5:
			buffer.loadFromFile("a.wav");
			break;
	}
	sound.setVolume(100.f);
	sound.setBuffer(buffer);
}
void Audio::playSound(const char type) {
	press = !press;
	if (press) {
		switch (type) {
			case 'c':
				loadSound(1, buffer, sound);
				sound.play();
				break;
			case 's':
				loadSound(2, buffer, sound);
				sound.play();
				break;
			case 'e':
				loadSound(3, buffer, sound);
				sound.play();
				break;
			case 'h':
				sound.setBuffer(explosion);
				sound.play();
				break;
			default:
				break;
		}
	}
}