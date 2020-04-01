#include "InputComponent.h"
#include "GameObject.h"

using namespace std;
InputComponent::InputComponent(sol::state &_lua)
{
	name = "InputComponent";

	if (_lua["Input"].valid())
		Input = _lua["Input"];
}


InputComponent::~InputComponent()
{

}

void InputComponent::InputStarted(sf::Keyboard::Key keyCode)
{
	if (Input)
		Input(true, keyCode);
}

void InputComponent::InputEnded(sf::Keyboard::Key keyCode)
{
	if (Input)
		Input(false, keyCode);
}