#pragma once

#include <GLFW/glfw3.h>
#include <Event/WindowEvent.h>

namespace Cosmos
{
	class COSMOS_API Window
	{
		using EventCallbackFn = std::function<void(Event&)>;

		struct WindowData
		{
			uint32_t Width, Height;
			const char* Title;

			EventCallbackFn EventCallback;
		};

		GLFWwindow* m_BaseWindow;
		WindowData m_Data;
	public:
		Window(uint32_t width, uint32_t height, const char* title);
		~Window();

		void Create();
		void Destroy() const;
		void Update() const;
		void SetEventCallback(const EventCallbackFn& callback) { m_Data.EventCallback = callback; }
	};
}