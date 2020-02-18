#include "AudioComponent.h"
using namespace std;

AudioComponent::AudioComponent()
{
	name = "AudioComponent";

}

AudioComponent::AudioComponent(string fileToSet)
{
	name = "AudioComponent";
	setAudio(fileToSet);
}

AudioComponent::~AudioComponent(void)
{
}

void AudioComponent::Update(float dt)
{
}

void AudioComponent::setAudio(string fileToSet)
{
	if (!audioFile.openFromFile(fileToSet))
	{
		fileLoaded = false;
		return;
	}

	fileLoaded = true;
}

void AudioComponent::PlayAudio()
{
	if (fileLoaded)
	{
		audioFile.play();
	}
}
