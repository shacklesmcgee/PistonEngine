#ifndef DEMO_EVENT_H__
#define DEMO_EVENT_H__

#include "Event.h"

class DemoEvent : public Event
{
public:
	DemoEvent();
	virtual ~DemoEvent();

	static constexpr DescriptorType descriptor = "DemoEvent";

	virtual DescriptorType type() const;
};

#endif