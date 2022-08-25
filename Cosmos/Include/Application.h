#pragma once

#include "Core.h"

namespace Cosmos
{
	class COSMOS_API Application
	{
	public:
		Application();
		~Application();

		void Run();
	};

	// To be defined in a Cosmos client
	Application* CreateApplication();
}