#include <SFML/Audio.hpp>

class Audio {
public:
	Audio();
	void playSound(const char type);
	bool press;
private:
	sf::Sound sound;
	sf::SoundBuffer buffer;
	sf::SoundBuffer explosion;
};
