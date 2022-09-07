#pragma once

#include "core/window.h"

#include "graphics/vao_loader.h"
#include "graphics/shader.h"

namespace Cosmos
{
	class Application
	{
		bool m_Running = true;

		std::unique_ptr<Window> m_Window;
		std::unique_ptr<VAOLoader> m_VAOLoader;
		std::unique_ptr<StaticShader> m_Shader;

		void Stop();

		void OnEvent(Event& e);
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e) const;
	public:
		COSMOS_API Application();

		COSMOS_API void Run() const;
	};

	// To be defined in a Cosmos client
	Application* CreateApplication();
}