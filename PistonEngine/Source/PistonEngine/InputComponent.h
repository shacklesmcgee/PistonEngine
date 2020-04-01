#pragma once
#include "BaseComponent.h"
#include "Event.h"

class InputComponent : public BaseComponent
{
public:
	InputComponent(sol::state &_lua);
	~InputComponent();

	std::function<void(bool, int)> Input;
	void InputStarted(sf::Keyboard::Key  keyCode);
	void InputEnded(sf::Keyboard::Key  keyCode);

private:

};

