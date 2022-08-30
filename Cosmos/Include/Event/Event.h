#pragma once

#include <cspch.h>
#include "Core/Core.h"

#define EVENT_FUNC(type) static EventType GetStaticType() { return EventType::type; } \
						 virtual EventType GetEventType() const override { return GetStaticType(); } \
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
		friend class EventDispatcher;
	protected:
		bool m_Handled = false;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual std::string ToString() const { return GetName(); }
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;

		Event& m_Event;
	public:
		EventDispatcher(Event& event)
			: m_Event(event) { }

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(*(T*) &m_Event);
				return true;
			}

			return false;
		}
	};
}