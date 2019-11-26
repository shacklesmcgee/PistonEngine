#include "Windows.h"

#include "Event.h"
#include "DemoEvent.h"
#include "MouseEvent.h"

class ClassObserver
{
public:
	void handle(const Event& e)
	{
		if (e.type() == DemoEvent::descriptor)
		{
			// This demonstrates how to obtain the underlying event type in case a
			// slot is set up to handle multiple events of different types.
			const DemoEvent& demoEvent = static_cast<const DemoEvent&>(e);
			OutputDebugString("class observer started\n");
		}

		if (e.type() == MouseEvent::descriptor)
		{
			// This demonstrates how to obtain the underlying event type in case a
			// slot is set up to handle multiple events of different types.
			const MouseEvent& mouseEvent = static_cast<const MouseEvent&>(e);
			if (mouseEvent.Button == 0 && mouseEvent.pressed)
				OutputDebugString("left mouse pressed\n");

			else if (mouseEvent.Button == 0 && mouseEvent.released)
				OutputDebugString("left mouse released\n");

			else if (mouseEvent.Button == 1 && mouseEvent.pressed)
				OutputDebugString("Right mouse pressed\n");

			else if (mouseEvent.Button == 1 && mouseEvent.released)
				OutputDebugString("Right mouse released\n");
		}
	}
};