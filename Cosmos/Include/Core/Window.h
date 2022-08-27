#pragma once

#include <GLFW/glfw3.h>

namespace Cosmos
{
	class COSMOS_API Window
	{
		GLFWwindow* m_BaseWindow;
		uint32_t m_Width, m_Height;
		const char* m_Title;
	public:
		Window(uint32_t width, uint32_t height, const char* title);
		~Window();

		void Create();
		void Destroy();
		void Update();
	};
}