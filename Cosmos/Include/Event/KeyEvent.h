#pragma once

#include "Event/Event.h"

namespace Cosmos
{
	class COSMOS_API KeyEvent : public Event
	{
	protected:
		int m_KeyCode;

		KeyEvent(int keycode)
			: m_KeyCode(keycode) { }

	public:
		inline int GetKeyCode() const { return m_KeyCode; }
	};

	class COSMOS_API KeyPressedEvent : public KeyEvent
	{
		int m_IsRepeat;
	public:
		KeyPressedEvent(int keycode, int isRepeat)
			: KeyEvent(keycode), m_IsRepeat(isRepeat) { }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent fired (key=" << m_KeyCode << ", repeat=" << m_IsRepeat << ")";
			return ss.str();
		}

		inline int GetRepeatCount() const { return m_IsRepeat; }

		EVENT_FUNC(KeyPressed)
	};

	class COSMOS_API KeyReleasedEvent : public KeyEvent
	{
	public:
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