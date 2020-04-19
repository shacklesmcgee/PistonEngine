#include "InputComponent.h"
#include "GameObject.h"

using namespace std;
InputComponent::InputComponent(sol::state &_lua)
{
	name = "InputComponent";

	if (_lua["MouseInput"].valid())
		LuaMouseInput = _lua["MouseInput"];

	if (_lua["KeyInput"].valid())
		LuaKeyInput = _lua["KeyInput"];
}


InputComponent::~InputComponent()
{

}

void InputComponent::MouseInput(bool state, sf::Keyboard::Key keyCode, sf::Vector2i mousePos)
{
	if (LuaMouseInput)
		LuaMouseInput(state, keyCode, mousePos.x, mousePos.y);
}

void InputComponent::KeyInput(bool state, sf::Keyboard::Key keyCode, sf::Vector2i mousePos)
{
	if (LuaKeyInput)
		LuaKeyInput(state, keyCode, mousePos.x, mousePos.y);
}