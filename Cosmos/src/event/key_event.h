#pragma once

#include "event/event.h"

namespace Cosmos
{
	struct COSMOS_API KeyEvent : Event
	{
	protected:
		int m_KeyCode;

		KeyEvent(int keycode)
			: m_KeyCode(keycode) { }
	public:
		int GetKeyCode() const { return m_KeyCode; }
	};

	struct COSMOS_API KeyPressedEvent : KeyEvent
	{
	private:
		int m_Repeat;
	public:
		KeyPressedEvent(int keycode, int repeat)
			: KeyEvent(keycode), m_Repeat(repeat) { }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent fired (key=" << m_KeyCode << ", repeat=" << m_Repeat << ")";
			return ss.str();
		}

		int GetRepeatCount() const { return m_Repeat; }

		EVENT_FUNC(KeyPressed)
	};

	struct COSMOS_API KeyReleasedEvent : KeyEvent
	{
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) { }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent fired (key=" << m_KeyCode << ")";
			return ss.str();
		}

		EVENT_FUNC(KeyReleased)
	};
}