#include "InputEvent.h"
//#include <iostream>

// This definition is still required in order to comply with the ODR of C++.
constexpr InputEvent::DescriptorType InputEvent::descriptor;

InputEvent::InputEvent(bool keyPressed, sf::Event e, sf::Vector2i mousePosAtEvent)
{
	pressed = keyPressed;
	released = !pressed;
	keyCode = e.key.code;

	isMouse = false;
	mousePos = mousePosAtEvent;
	if (e.type == sf::Event::MouseButtonPressed || e.type == sf::Event::MouseButtonReleased)
	{
		isMouse = true;
	}

}


InputEvent::~InputEvent()
{
}

Event::DescriptorType InputEvent::type() const
{

	return descriptor;
}