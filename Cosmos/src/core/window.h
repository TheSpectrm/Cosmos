/* WINDOW IMPLEMENTATION */
#pragma once

#include <glad/glad.h>
#include <glfw/glfw3.h>

#include "core/csdefs.h"
#include "event/key_event.h"
#include "event/mouse_event.h"
#include "event/window_event.h"

namespace Cosmos
{
	class CS_API Window
	{
		using EventCallbackFn = std::function<void(Event&)>;

		struct WindowData
		{
			uint16_t Width = 0, Height = 0;
			std::string Title;

			EventCallbackFn EventCallback;
		};

		GLFWwindow* m_BaseWindow;
		WindowData m_Data;
	public:
		Window(const uint16_t& width, const uint16_t& height, const std::string& title);
		~Window();

		void Create();
		void Destroy() const;
		void Update() const;

		void SetEventCallback(const EventCallbackFn& callback);
		WindowData GetData() const;
	};
}