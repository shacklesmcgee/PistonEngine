#ifndef DEMO_EVENT_H__
#define DEMO_EVENT_H__

#include "Event.h"
#include "Windows.h"
#undef max
#undef min
class DemoEvent : public Event
{
public:
	DemoEvent();
	virtual ~DemoEvent();

	static constexpr DescriptorType descriptor = "DemoEvent";

	virtual DescriptorType type() const;
};

#endif