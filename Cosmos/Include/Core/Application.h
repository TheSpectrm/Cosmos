#pragma once

#include "Core/Window.h"
#include "Graphics/VAOLoader.h"

namespace Cosmos
{
	class COSMOS_API Application
	{
		bool m_Running;
		std::unique_ptr<Window> m_Window;
	public:
		Application();

		void Run() const;
	private:
		void OnEvent(Event& e);
		bool OnWindowClose(WindowCloseEvent& e);
	};

	// To be defined in a Cosmos client
	Application* CreateApplication();
}