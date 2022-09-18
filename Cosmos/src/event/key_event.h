/* KEY EVENT IMPLEMENTATION */
#pragma once

#include "event/event.h"

namespace Cosmos
{
	struct CS_API KeyEvent : Event
	{
		uint16_t KeyCode;

		KeyEvent(uint16_t keycode)
			: KeyCode(keycode) { }
	};

	struct CS_API KeyPressedEvent : KeyEvent
	{
		bool Repeat;

		KeyPressedEvent(uint16_t keycode, bool repeat)
			: KeyEvent(keycode), Repeat(repeat) { }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent fired (key=" << KeyCode << ", repeat=" << Repeat << ")";
			return ss.str();
		}

		EVENT_FUNC(KeyPressed)
	};

	struct CS_API KeyReleasedEvent : KeyEvent
	{
		KeyReleasedEvent(uint16_t keycode)
			: KeyEvent(keycode) { }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent fired (key=" << KeyCode << ")";
			return ss.str();
		}

		EVENT_FUNC(KeyReleased)
	};
}