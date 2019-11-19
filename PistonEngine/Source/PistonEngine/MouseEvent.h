#ifndef MOUSE_EVENT_H__
#define MOUSE_EVENT_H__

#include "Event.h"

class MouseEvent : public Event
{
public:
	MouseEvent();
	virtual ~MouseEvent();

	static constexpr DescriptorType descriptor = "MouseEvent";

	virtual DescriptorType type() const;
};

#endif