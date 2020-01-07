#include "DemoEvent.h"
#include <iostream>

// This definition is still required in order to comply with the ODR of C++.
constexpr DemoEvent::DescriptorType DemoEvent::descriptor;

DemoEvent::DemoEvent()
{
	OutputDebugString("demo event started\n");
}

DemoEvent::~DemoEvent()
{
	OutputDebugString("demo event destroyed\n");
}

Event::DescriptorType DemoEvent::type() const
{
	return descriptor;
}