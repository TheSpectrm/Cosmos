#pragma once

#include <cspch.h>
#include "Core/Core.h"

#define EVENT_FUNC(type) virtual EventType GetEventType() const override { return EventType::type; } \
						 virtual const char* GetName() const override { return #type "Event fired"; }

namespace Cosmos
{
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	class COSMOS_API Event
	{
	public:
		bool m_Handled = false;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual std::string ToString() const { return GetName(); }
	};
}