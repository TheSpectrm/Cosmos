#pragma once

#include "Core/Window.h"

namespace Cosmos
{
	class COSMOS_API Application
	{
		std::unique_ptr<Window> m_Window;
	public:
		Application();

		void Run() const;
		void OnEvent(Event& e) const;
	};

	// To be defined in a Cosmos client
	Application* CreateApplication();
}