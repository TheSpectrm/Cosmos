/* APPLICATION IMPLEMENTATION */
#pragma once

#include "core/csdefs.h"
#include "core/window.h"
#include "graphics/shader.h"
#include "entity/entity.h"

namespace Cosmos
{
	class CS_API Application
	{
		bool m_Running = true;

		std::unique_ptr<Window> m_Window;
		std::unique_ptr<StaticShader> m_Shader;

		Model* m_Model;
		Entity* m_Entity;

		void Stop();
		void Render(Entity* entity) const;

		void OnEvent(Event& e);
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e) const;
		bool OnKeyPressed(KeyPressedEvent& e) const;
	public:
		Application();

		void Run() const;
	};

	// To be defined in a Cosmos client
	Application* CreateApplication();
}