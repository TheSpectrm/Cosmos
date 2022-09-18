/* MOUSE EVENT IMPLEMENTATION */
#pragma once

#include "event/event.h"

namespace Cosmos
{
	struct CS_API MouseMovedEvent : Event
	{
		float XPos, YPos;

		MouseMovedEvent(float xPos, float yPos)
			: XPos(xPos), YPos(yPos) { }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent fired (x=" << XPos << ", y=" << YPos << ")";
			return ss.str();
		}

		EVENT_FUNC(MouseMoved)
	};

	struct CS_API MouseScrolledEvent : Event
	{
		float XOffset, YOffset;

		MouseScrolledEvent(float xOffset, float yOffset)
			: XOffset(xOffset), YOffset(yOffset) { }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent fired (xOffset=" << XOffset << ", yOffset=" << YOffset << ")";
			return ss.str();
		}

		EVENT_FUNC(MouseScrolled)
	};

	struct CS_API MouseButtonEvent : Event
	{
		uint8_t Button;

		MouseButtonEvent(uint8_t button)
			: Button(button) { }
	};

	struct CS_API MouseButtonPressedEvent : MouseButtonEvent
	{
		MouseButtonPressedEvent(uint8_t button)
			: MouseButtonEvent(button) { }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent fired (button=" << Button << ")";
			return ss.str();
		}

		EVENT_FUNC(MouseButtonPressed)
	};

	struct CS_API MouseButtonReleasedEvent : MouseButtonEvent
	{
		MouseButtonReleasedEvent(uint8_t button)
			: MouseButtonEvent(button) { }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent fired (button=" << Button << ")";
			return ss.str();
		}

		EVENT_FUNC(MouseButtonReleased)
	};
}