#include "AudioComponent.h"
#include "GameObject.h"

using namespace std;

AudioComponent::AudioComponent(sol::state& _lua)
{
	name = "AudioComponent";

	_lua.set("AudioComp", this);

	_lua["PlaySound"] = &AudioComponent::PlayAudio;
	_lua["PlaySoundFile"] = &AudioComponent::PlayAudioFile;
}

AudioComponent::AudioComponent(string fileToSet, sol::state& _lua)
{
	name = "AudioComponent";
	setAudio(fileToSet);

	_lua.set("Audio", this);

	_lua["PlaySound"] = &AudioComponent::PlayAudio;
	_lua["PlaySoundFile"] = &AudioComponent::PlayAudioFile;
}

AudioComponent::~AudioComponent(void)
{
}

void AudioComponent::Test()
{
	cout << "test" << endl;
}


void AudioComponent::Update(float dt)
{
}

void AudioComponent::setAudio(string fileLoc)
{
	if (!audioFile.openFromFile(fileLoc))
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


void AudioComponent::PlayAudioFile(string fileLoc)
{
	setAudio(fileLoc);

	if (fileLoaded)
	{
		audioFile.play();
	}
}
