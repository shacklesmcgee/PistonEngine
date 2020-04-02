#pragma once
#include "BaseComponent.h"
#include "Event.h"

class InputComponent : public BaseComponent
{
public:
	InputComponent(sol::state &_lua);
	~InputComponent();

	std::function<void(bool, int)> LuaMouseInput;
	std::function<void(bool, int)> LuaKeyInput;

	void MouseInput(bool state, sf::Keyboard::Key  keyCode);
	void KeyInput(bool state, sf::Keyboard::Key  keyCode);

private:

};

