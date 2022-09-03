#pragma once

#include "Core/Window.h"
#include "Graphics/VAOLoader.h"
#include "Graphics/Shader.h"

namespace Cosmos
{
	class Application
	{
	public:
		COSMOS_API Application();

		COSMOS_API void Run() const;
	private:
		bool m_Running;
		std::unique_ptr<Window> m_Window;

		void OnEvent(Event& e);
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	};

	// To be defined in a Cosmos client
	Application* CreateApplication();
}