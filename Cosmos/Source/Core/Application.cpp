#include <cspch.h>
#include "Core/Application.h"

namespace Cosmos
{
	#define WIDTH  3
	#define HEIGHT 2
	#define SCALE  450

	#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		CS_CORE_INFO("Created and initialized application");
		m_Window = std::unique_ptr<Window>(new Window(SCALE * WIDTH, SCALE * HEIGHT, "Cosmos Window"));
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	void Application::Run() const
	{
		while (true)
		{
			glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
			m_Window->Update();
		}
	}

	void Application::OnEvent(Event& e) const
	{
		CS_CORE_TRACE(e.ToString().c_str());
	}
}