#pragma once

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

#include "Event/WindowEvent.h"
#include "Event/KeyEvent.h"
#include "Event/MouseEvent.h"

namespace Cosmos
{
	class COSMOS_API Window
	{
		using EventCallbackFn = std::function<void(Event&)>;

		struct WindowData
		{
			uint32_t Width, Height;
			std::string Title;

			EventCallbackFn EventCallback;
		};

		GLFWwindow* m_BaseWindow;
	public:
		WindowData m_Data;

		Window(uint32_t width, uint32_t height, const std::string& title);
		~Window();

		void Create();
		void Destroy() const;
		void Update() const;
		void SetEventCallback(const EventCallbackFn& callback) { m_Data.EventCallback = callback; }
	};
}