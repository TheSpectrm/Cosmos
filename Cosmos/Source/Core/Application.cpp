#include <cspch.h>
#include "Core/Application.h"

#define WIDTH  3
#define HEIGHT 2
#define SCALE  450

namespace Cosmos
{
	Application::Application()
		: m_Window()
	{
		CS_CORE_SUCCESS("Created and initialized application");
		m_Window = new Window(SCALE * WIDTH, SCALE * HEIGHT, "Cosmos Window");
	}

	Application::~Application() 
	{
		delete m_Window;
	}

	void Application::Run()
	{
		while (true)
		{
			glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
			m_Window->Update();
		}
	}
}