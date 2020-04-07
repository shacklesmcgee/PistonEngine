#include "Event.h"

#undef max
#undef min
class InputEvent : public Event
{
public:
	InputEvent(bool keyPressed, sf::Event e);
	virtual ~InputEvent();

	static constexpr DescriptorType descriptor = "InputEvent";

	virtual DescriptorType type() const;

	bool pressed;
	bool released;
	sf::Keyboard::Key keyCode;

	bool isMouse;
};
