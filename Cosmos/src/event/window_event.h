/* WINDOW EVENT IMPLEMENTATION */
#pragma once

#include "event/event.h"

namespace Cosmos
{
	struct CS_API WindowCloseEvent : Event
	{
		WindowCloseEvent() = default;

		EVENT_FUNC(WindowClose)
	};

	struct CS_API WindowResizeEvent : Event
	{
		uint16_t Width, Height;

		WindowResizeEvent(uint16_t width, uint16_t height)
			: Width(width), Height(height) { }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent fired (width=" << Width << ", height=" << Height << ")";
			return ss.str();
		}

		EVENT_FUNC(WindowResize)
	};
}