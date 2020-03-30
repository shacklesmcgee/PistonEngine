#include "InputEvent.h"
#include <iostream>

// This definition is still required in order to comply with the ODR of C++.
constexpr InputEvent::DescriptorType InputEvent::descriptor;

InputEvent::InputEvent(bool keyPressed, sf::Event e)
{
	pressed = keyPressed;
	released = !pressed;
	Button = e.key.code;


	//std::cout << "InputEvent created\n" << "button is: " << Button << std::endl;
}

InputEvent::~InputEvent()
{
	//std::cout << "InputEvent destroyed\n" << std::endl;
}

Event::DescriptorType InputEvent::type() const
{
	return descriptor;
}