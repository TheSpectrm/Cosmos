#include <stdio.h>
#include "Core/Logger.h"
#include "Core/Application.h"

namespace Cosmos
{
	Application::Application() 
	{
		CS_CORE_INFO("Created an application");
	}

	Application::~Application() { }

	void Application::Run()
	{
		while (true);
	}
}