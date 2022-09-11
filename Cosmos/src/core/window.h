#pragma once

#include <glad/glad.h>
#include <glfw/glfw3.h>

#include "event/key_event.h"
#include "event/mouse_event.h"
#include "event/window_event.h"

namespace Cosmos
{
	class CS_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		struct WindowData
		{
			uint32_t Width = 0, Height = 0;
			std::string Title;

			EventCallbackFn EventCallback;
		};
	private:
		GLFWwindow* m_BaseWindow;
		WindowData m_Data;
	public:
		Window(uint32_t width, uint32_t height, const std::string& title);
		~Window();

		void Create();
		void Destroy() const;
		void Update() const;

		void SetEventCallback(const EventCallbackFn& callback);
		WindowData GetData() const;
	};
}