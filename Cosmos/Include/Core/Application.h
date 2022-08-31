#pragma once

#include "Core/Window.h"

namespace Cosmos
{
	class COSMOS_API Application
	{
		bool m_Running;
		std::unique_ptr<Window> m_Window;
	public:
		Application();

		void Run() const;
		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
	};

	// To be defined in a Cosmos client
	Application* CreateApplication();
}