#ifndef MOUSE_EVENT_H__
#define MOUSE_EVENT_H__

#include "Event.h"

class MouseEvent : public Event
{
public:
	MouseEvent(bool keyPressed, int key);
	virtual ~MouseEvent();

	static constexpr DescriptorType descriptor = "MouseEvent";

	virtual DescriptorType type() const;

	bool pressed;
	bool released;
	int Button;
};

#endif