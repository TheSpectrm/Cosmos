#include <cspch.h>
#include "Core/Window.h"

#define GLFW_MINOR 3
#define GLFW_MAJOR 3

namespace Cosmos
{
	Window::Window(uint32_t width, uint32_t height, const char* title)
	{
		m_BaseWindow = null;
		m_Data.Width = width;
		m_Data.Height = height;
		m_Data.Title = title;
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

		m_BaseWindow = glfwCreateWindow(m_Data.Width, m_Data.Height, m_Data.Title, null, null);

		if (!m_BaseWindow)
		{
			CS_CORE_ERROR("Failed to create GLFW window");
			return;
		}
		CS_CORE_SUCCESS("Created GLFW window (width=%d, height=%d, title='%s')", m_Data.Width, m_Data.Height, m_Data.Title);
		glfwMakeContextCurrent(m_BaseWindow);
		glfwSetWindowUserPointer(m_BaseWindow, &m_Data);

		glfwSetWindowCloseCallback(m_BaseWindow, [](GLFWwindow* window) 
		{
			WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);

			WindowCloseEvent event;
			data.EventCallback(event);
		});

		glfwSetWindowSizeCallback(m_BaseWindow, [](GLFWwindow* window, int width, int height) 
		{
			WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);
			data.Width = width;
			data.Height = height;

			WindowResizeEvent event(width, height);
			data.EventCallback(event);
		});
	}

	void Window::Destroy() const
	{
		glfwDestroyWindow(m_BaseWindow);
		CS_CORE_INFO("Destroyed GLFW window");
		glfwTerminate();
		CS_CORE_INFO("Terminated GLFW %d.%d", GLFW_MAJOR, GLFW_MINOR);
	}

	void Window::Update() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwSwapBuffers(m_BaseWindow);
		glfwPollEvents();
	}
}