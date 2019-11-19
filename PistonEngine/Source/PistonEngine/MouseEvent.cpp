#include "MouseEvent.h"
#include "Windows.h"
#include <iostream>

// This definition is still required in order to comply with the ODR of C++.
constexpr MouseEvent::DescriptorType MouseEvent::descriptor;

MouseEvent::MouseEvent()
{
	OutputDebugString("Mouse event started\n");
}

MouseEvent::~MouseEvent()
{
	OutputDebugString("Mouse event destroyed\n");
}

Event::DescriptorType MouseEvent::type() const
{
	return descriptor;
}