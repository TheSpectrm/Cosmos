#include <cspch.h>
#include "Core/Application.h"

namespace Cosmos
{
	Application::Application()
		: m_Window()
	{
		CS_CORE_SUCCESS("Created and initialized an application");
		m_Window = new Window(400, 400, "Test Window");
	}

	Application::~Application() 
	{
		delete m_Window;
	}

	void Application::Run()
	{
		while (true)
		{
			m_Window->Update();
		}
	}
}