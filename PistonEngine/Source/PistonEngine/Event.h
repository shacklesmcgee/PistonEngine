#ifndef EVENT_H__
#define EVENT_H__

#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

/**
  @class Event
  @brief Base class for all events
  This class provides the interface that needs to be implemented by an event.
  Each dependent class is required to implement type() to uniquely identify
  events. As a convenience, each class should have a static descriptor so that
  clients may refer to it without having to create an instance.
  Unfortunately, I have no idea how to enforce the existence of this attribute.
*/

class Event
{
public:
	virtual~Event();

	using DescriptorType = const char*;

	/** @returns The descriptor type of this event */
	virtual DescriptorType type() const = 0;

};

#endif