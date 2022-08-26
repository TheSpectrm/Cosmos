#pragma once

#include "Core/Core.h"

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