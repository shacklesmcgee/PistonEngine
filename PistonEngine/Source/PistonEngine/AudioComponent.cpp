#include "AudioComponent.h"
using namespace std;

AudioComponent::AudioComponent(sol::state& _lua)
{
	name = "AudioComponent";

	_lua.set("Audio", this);

	_lua["PlaySound"] = &AudioComponent::PlayAudio;

}

AudioComponent::AudioComponent(string fileToSet, sol::state& _lua)
{
	name = "AudioComponent";
	setAudio(fileToSet);

	_lua.set("Audio", this);

	_lua["PlaySound"] = &AudioComponent::PlayAudio;
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
