#pragma once

#include "event/event.h"

namespace Cosmos
{
	struct CS_API MouseMovedEvent : Event
	{
	private:
		float m_MouseX, m_MouseY;
	public:
		MouseMovedEvent(float x, float y)
			: m_MouseX(x), m_MouseY(y) { }

		float GetX() const { return m_MouseX; }
		float GetY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent fired (x=" << m_MouseX << ", y=" << m_MouseY << ")";
			return ss.str();
		}

		EVENT_FUNC(MouseMoved)
	};

	struct CS_API MouseScrolledEvent : Event
	{
	private:
		float m_XOffset, m_YOffset;
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: m_XOffset(xOffset), m_YOffset(yOffset) { }

		float GetXOffset() const { return m_XOffset; }
		float GetYOffset() const { return m_YOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent fired (xOffset=" << m_XOffset << ", yOffset=" << m_YOffset << ")";
			return ss.str();
		}

		EVENT_FUNC(MouseScrolled)
	};

	struct CS_API MouseButtonEvent : Event
	{
	protected:
		int m_Button;

		MouseButtonEvent(int button)
			: m_Button(button) { }

	public:
		int GetMouseButton() const { return m_Button; }
	};

	struct CS_API MouseButtonPressedEvent : MouseButtonEvent
	{
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) { }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent fired (button=" << m_Button << ")";
			return ss.str();
		}

		EVENT_FUNC(MouseButtonPressed)
	};

	struct CS_API MouseButtonReleasedEvent : MouseButtonEvent
	{
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) { }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent fired (button=" << m_Button << ")";
			return ss.str();
		}

		EVENT_FUNC(MouseButtonReleased)
	};
}