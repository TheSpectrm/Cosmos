#include <cspch.h>
#include "Core/Window.h"

#define GLFW_MINOR 3
#define GLFW_MAJOR 3

namespace Cosmos
{
	Window::Window(uint32_t width, uint32_t height, const char* title)
		: m_BaseWindow(), m_Width(width), m_Height(height), m_Title(title)
	{ 
		Create();
	}

	Window::~Window() 
	{ 
		Destroy();
	}

	void Window::Create()
	{
		if (!glfwInit())
		{
			CS_CORE_ERROR("Failed to initialize GLFW %d.%d", GLFW_MAJOR, GLFW_MINOR);
			return;
		}
		CS_CORE_SUCCESS("Initialized GLFW %d.%d", GLFW_MAJOR, GLFW_MINOR);

		m_BaseWindow = glfwCreateWindow(m_Width, m_Height, m_Title, null, null);

		if (!m_BaseWindow)
		{
			CS_CORE_ERROR("Failed to create a GLFW window");
			return;
		}
		CS_CORE_SUCCESS("Created a GLFW window (width=%d, height=%d, title='%s')", m_Width, m_Height, m_Title);
		glfwMakeContextCurrent(m_BaseWindow);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Window::Destroy()
	{
		glfwDestroyWindow(m_BaseWindow);
		CS_CORE_INFO("Destroyed a GLFW window");
		glfwTerminate();
		CS_CORE_INFO("Terminated GLFW %d.%d", GLFW_MAJOR, GLFW_MINOR);
	}

	void Window::Update()
	{
		glfwSwapBuffers(m_BaseWindow);
		glfwPollEvents();
	}
}