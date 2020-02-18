#pragma once

#include "BaseComponent.h"
#include "SFML/Audio.hpp"
#include <string.h>

using namespace std;

class AudioComponent : public BaseComponent
{
public:
	AudioComponent();
	AudioComponent(string fileToSet);

	~AudioComponent(void);

	virtual void Update(float dt);

	void setAudio(string fileToSet);
	void PlayAudio();

	bool fileLoaded = false;

protected:
	sf::Music audioFile;
};
