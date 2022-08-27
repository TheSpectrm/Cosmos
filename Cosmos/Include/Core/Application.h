#pragma once

#include "Core/Window.h"

namespace Cosmos
{
	class COSMOS_API Application
	{
		Window* m_Window;
	public:
		Application();
		~Application();

		void Run();
	};

	// To be defined in a Cosmos client
	Application* CreateApplication();
}