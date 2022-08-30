#pragma once

#include "Event/Event.h"

namespace Cosmos
{
	class COSMOS_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() = default;

		EVENT_FUNC(WindowClose)
	};

	class COSMOS_API WindowResizeEvent : public Event
	{
		uint32_t m_Width, m_Height;
	public:
		WindowResizeEvent(uint32_t width, uint32_t height)
			: m_Width(width), m_Height(height) { }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent fired (width=" << m_Width << ", height=" << m_Height << ")";
			return ss.str();
		}

		EVENT_FUNC(WindowResize)
	};
}