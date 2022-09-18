#include <cspch.h>
#include "core/window.h"

namespace Cosmos
{
	static void GLFWErrorCallback(int error, const char* description)
	{
		CORE_ERROR("GLFW Error %d: %s", error, description);
	}

	Window::Window(const uint16_t& width, const uint16_t& height, const std::string& title)
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

	void Window::Create()
	{
		if (!glfwInit())
		{
			CORE_ERROR("Failed to initialize GLFW 3.3");
			return;
		}

		CORE_INFO("Initialized GLFW 3.3");
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		glfwSetErrorCallback(GLFWErrorCallback);

		m_BaseWindow = glfwCreateWindow(m_Data.Width, m_Data.Height, m_Data.Title.c_str(), null, null);

		if (!m_BaseWindow)
		{
			CORE_ERROR("Failed to create GLFW window");
			return;
		}

		CORE_INFO("Created GLFW window (width=%d, height=%d, title='%s')", m_Data.Width, m_Data.Height, m_Data.Title.c_str());
		glfwMakeContextCurrent(m_BaseWindow);
		glfwSetWindowUserPointer(m_BaseWindow, &m_Data);

		gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
		CORE_INFO("Initialized GLAD 4.6");

		glfwSetWindowCloseCallback(m_BaseWindow, [](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);

			WindowCloseEvent e;
			data.EventCallback(e);
		});

		glfwSetWindowSizeCallback(m_BaseWindow, [](GLFWwindow* window, int width, int height)
		{
			WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);
			data.Width = width;
			data.Height = height;

			WindowResizeEvent e(width, height);
			data.EventCallback(e);
		});

		glfwSetKeyCallback(m_BaseWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent e(key, 0);
					data.EventCallback(e);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent e(key);
					data.EventCallback(e);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent e(key, 1);
					data.EventCallback(e);
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
					MouseButtonPressedEvent e(button);
					data.EventCallback(e);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent e(button);
					data.EventCallback(e);
					break;
				}
			}
		});

		glfwSetScrollCallback(m_BaseWindow, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);

			MouseScrolledEvent e((float) xOffset, (float) yOffset);
			data.EventCallback(e);
		});

		glfwSetCursorPosCallback(m_BaseWindow, [](GLFWwindow* window, double xPos, double yPos)
		{
			WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);

			MouseMovedEvent e((float) xPos, (float) yPos);
			data.EventCallback(e);
		});
	}

	void Window::Destroy() const
	{
		glfwDestroyWindow(m_BaseWindow);
		CORE_INFO("Destroyed GLFW window");
		glfwTerminate();
		CORE_INFO("Terminated GLFW 3.3");
	}

	void Window::Update() const
	{
		glfwPollEvents();
		glfwSwapBuffers(m_BaseWindow);
	}

	void Window::SetEventCallback(const EventCallbackFn& callback)
	{
		m_Data.EventCallback = callback;
	}

	Window::WindowData Window::GetData() const
	{
		return m_Data;
	}
}