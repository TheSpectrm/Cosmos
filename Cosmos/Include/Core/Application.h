#pragma once

#include "Core/Window.h"

namespace Cosmos
{
	class COSMOS_API Application
	{
		Window* m_Window;
	public:
		Application();
		~Application() = default;

		void Run() const;
		void OnEvent(Event& e) const;
	};

	// To be defined in a Cosmos client
	Application* CreateApplication();
}