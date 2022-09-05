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
		void Stop();
		void OnEvent(Event& e);
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

		bool m_Running;
		std::unique_ptr<Window> m_Window;
		std::unique_ptr<VAOLoader> m_VAOLoader;
		std::unique_ptr<StaticShader> m_Shader;
	};

	// To be defined in a Cosmos client
	Application* CreateApplication();
}