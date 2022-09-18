/* EVENT INTERFACE */
#pragma once

#define EVENT_FUNC(type)\
	virtual EventType GetEventType() const override { return EventType::type; }\
	virtual std::string GetName() const override { return #type"Event fired"; }

namespace Cosmos
{
	enum class EventType : uint8_t
	{
		None = 0,
		WindowClose, WindowResize,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	struct CS_API Event
	{
		bool Handled = false;

		virtual EventType GetEventType() const = 0;
		virtual std::string GetName() const = 0;
		virtual std::string ToString() const { return GetName(); }
	};
}