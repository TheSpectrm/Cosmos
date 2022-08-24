#include <stdio.h>
#include "Application.h"

namespace Cosmos
{
	Application::Application()
	{
		printf("Application initialized!\n");
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (true)
			printf("Application running...\n");
	}
}