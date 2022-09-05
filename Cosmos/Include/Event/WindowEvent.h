#pragma once

#include "Event/Event.h"

namespace Cosmos
{
	struct COSMOS_API WindowCloseEvent : Event
	{
		WindowCloseEvent() = default;

		EVENT_FUNC(WindowClose)
	};

	struct COSMOS_API WindowResizeEvent : Event
	{
		WindowResizeEvent(uint32_t width, uint32_t height)
			: m_Width(width), m_Height(height) { }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent fired (width=" << m_Width << ", height=" << m_Height << ")";
			return ss.str();
		}

		EVENT_FUNC(WindowResize)
	private:
		uint32_t m_Width, m_Height;
	};
}