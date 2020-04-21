#pragma once

#include "BaseComponent.h"
#include "SFML/Audio.hpp"
#include <string.h>

using namespace std;

class AudioComponent : public BaseComponent
{
public:
	AudioComponent(sol::state& _lua);
	AudioComponent(string fileToSet, sol::state& _lua);

	~AudioComponent(void);

	virtual void Update(float dt);

	void setAudio(string fileLoc);
	void PlayAudio();
	void PlayAudioFile(string fileLoc);
	void Test();

	bool fileLoaded = false;

protected:
	sf::Music audioFile;
};

