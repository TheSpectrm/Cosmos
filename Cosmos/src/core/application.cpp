#include <cspch.h>
#include "core/application.h"

namespace Cosmos
{
	#define WIDTH  3
	#define HEIGHT 2
	#define SCALE  450

	void Application::Stop()
	{
		m_Running = false;
		m_Model->Destroy();
		m_Shader->Clean();
	}

	void Application::Render(Entity* entity) const
	{
		Cml::Mat4 modelMatrix = Cml::Identity();
		modelMatrix *= Cml::Translate(entity->Position);
		modelMatrix *= Cml::Rotate(entity->RotY, Cml::Vec3(0.0f, 1.0f, 0.0f));
		modelMatrix *= Cml::Scale(Cml::Vec3(entity->Scale, entity->Scale, entity->Scale));

		Cml::Mat4 projMatrix = Cml::Perspective(70.0f, (float)m_Window->GetData().Width / (float)m_Window->GetData().Height, 0.1f, 1000.0f);

		Model* model = entity->BaseModel;

		m_Shader->Start();

		m_Shader->SetMat4(m_Shader->GetUniformLocation("model_matrix"), modelMatrix);
		m_Shader->SetMat4(m_Shader->GetUniformLocation("proj_matrix"), projMatrix);
		entity->BaseModel->Render();

		m_Shader->Stop();
	}

	void Application::OnEvent(Event& e)
	{
		switch (e.GetEventType())
		{
		case EventType::WindowClose:
			e.Handled = OnWindowClose((WindowCloseEvent&) e);
			break;

		case EventType::WindowResize:
			e.Handled = OnWindowResize((WindowResizeEvent&) e);
			break;

		case EventType::KeyPressed:
			e.Handled = OnKeyPressed((KeyPressedEvent&) e);
			break;
		}

		CORE_TRACE(e.ToString().c_str());
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		Stop();
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& e) const
	{
		glViewport(0, 0, m_Window->GetData().Width, m_Window->GetData().Height);
		return true;
	}

	bool Application::OnKeyPressed(KeyPressedEvent& e) const
	{
		switch (e.KeyCode)
		{
		case 87:
			m_Entity->Position.Z += 0.2f;
			break;

		case 83:
			m_Entity->Position.Z -= 0.2f;
			break;
		}

		return true;
	}

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(new Window(SCALE * WIDTH, SCALE * HEIGHT, "Cosmos"));
		m_Shader = std::unique_ptr<StaticShader>(new StaticShader());
		
		CORE_INFO("Created and initialized application");

		m_Model = new Model({
			/* Vertices */
			-0.5f, 0.5f, 0.0f,
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			0.5f, 0.5f, 0.0f,
		}, {
			/* Indices */
			0, 1, 3,
			3, 1, 2
		});

		m_Entity = new Entity(m_Model, Cml::Vec3(0.0f, 0.0f, -1.0f), 0.0f, 0.0f, 0.0f, 1.0f);
		m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
	}

	void Application::Run() const
	{
		/* Main Program Loop */
		while (m_Running)
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glClearColor(1 / 255.0f * 98, 1 / 255.0f * 172, 1 / 255.0f * 236, 1.0f);

			Render(m_Entity);

			m_Window->Update();
		}
	}
}