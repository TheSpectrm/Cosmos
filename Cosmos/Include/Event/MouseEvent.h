#pragma once

#include "Event/Event.h"

namespace Cosmos
{
	class COSMOS_API MouseMovedEvent : public Event
	{
		float m_MouseX, m_MouseY;
	public:
		MouseMovedEvent(float x, float y)
			: m_MouseX(x), m_MouseY(y) { }

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent fired (x=" << m_MouseX << ", y=" << m_MouseY << ")";
			return ss.str();
		}

		EVENT_FUNC(MouseMoved)
	};

	class COSMOS_API MouseScrolledEvent : public Event
	{
		float m_XOffset, m_YOffset;
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: m_XOffset(xOffset), m_YOffset(yOffset) { }

		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent fired (xOffset=" << m_XOffset << ", yOffset=" << m_YOffset << ")";
			return ss.str();
		}

		EVENT_FUNC(MouseScrolled)
	};

	class COSMOS_API MouseButtonEvent : public Event
	{
	protected:
		int m_Button;

		MouseButtonEvent(int button)
			: m_Button(button) { }

	public:
		inline int GetMouseButton() const { return m_Button; }
	};

	class COSMOS_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
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

	class COSMOS_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
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