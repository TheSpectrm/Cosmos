#include <cspch.h>
#include "Core/Window.h"

namespace Cosmos
{
	#define GLFW_MINOR 3
	#define GLFW_MAJOR 3

	Window::Window(uint32_t width, uint32_t height, const char* title)
	{
		m_Data.Width = width;
		m_Data.Height = height;
		m_Data.Title = title;
		Create();
	}

	Window::~Window() 
	{ 
		Destroy();
	}

	static void GLFWErrorCallback(int error, const char* description)
	{
		CS_CORE_ERROR("GLFW Error %d: %s", error, description);
	}

	void Window::Create()
	{
		if (!glfwInit())
		{
			CS_CORE_ERROR("Failed to initialize GLFW %d.%d", GLFW_MAJOR, GLFW_MINOR);
			return;
		}

		CS_CORE_INFO("Initialized GLFW %d.%d", GLFW_MAJOR, GLFW_MINOR);
		glfwSetErrorCallback(GLFWErrorCallback);

		m_BaseWindow = glfwCreateWindow(m_Data.Width, m_Data.Height, m_Data.Title, null, null);

		if (!m_BaseWindow)
		{
			CS_CORE_ERROR("Failed to create GLFW window");
			return;
		}

		CS_CORE_INFO("Created GLFW window (width=%d, height=%d, title='%s')", m_Data.Width, m_Data.Height, m_Data.Title);
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

		glfwSetKeyCallback(m_BaseWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					data.EventCallback(event);
					break;
				}
			}
		});

		glfwSetMouseButtonCallback(m_BaseWindow, [](GLFWwindow* window, int button, int action, int mods)
		{
			WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.EventCallback(event);
					break;
				}
			}
		});

		glfwSetScrollCallback(m_BaseWindow, [](GLFWwindow* window, double xOffset, double yOffset) 
		{
			WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);

			MouseScrolledEvent event((float) xOffset, (float) yOffset);
			data.EventCallback(event);
		});

		glfwSetCursorPosCallback(m_BaseWindow, [](GLFWwindow* window, double xPos, double yPos)
		{
			WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);

			MouseMovedEvent event((float) xPos, (float) yPos);
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