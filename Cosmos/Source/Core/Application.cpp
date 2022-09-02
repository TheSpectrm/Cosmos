#include <cspch.h>
#include "Core/Application.h"

namespace Cosmos
{
	#define WIDTH  3
	#define HEIGHT 2
	#define SCALE  450

	Application::Application()
	{
		CS_CORE_INFO("Created and initialized application");
		m_Window = std::unique_ptr<Window>(new Window(SCALE * WIDTH, SCALE * HEIGHT, "Cosmos"));
		m_Running = true;

		m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
	}

	void Application::Run() const
	{
		std::vector<float> vertices({
			-0.5f, 0.5f, 0.0f,
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			0.5f, 0.5f, 0.0f,
		});

		std::vector<int> indices({
			0, 1, 3,
			3, 1, 2
		});

		VAOLoader loader = VAOLoader();
		StaticShader shader = StaticShader();
		Model* model = loader.LoadToVAO(vertices, indices);

		shader.Start();

		while (m_Running)
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glClearColor(0.0f, 0.0f, 1.0f, 0.0f);

			// Render the triangle model
			glBindVertexArray(model->m_VaoID);
			glDrawElements(GL_TRIANGLES, model->m_VertexCount, GL_UNSIGNED_INT, null);

			m_Window->Update();
		}

		loader.Clean();
		shader.Clean();
	}

	void Application::OnEvent(Event& e)
	{
		switch (e.GetEventType())
		{
		case EventType::WindowClose:
			e.m_Handled = OnWindowClose((WindowCloseEvent&) e);
			break;

		case EventType::WindowResize:
			e.m_Handled = OnWindowResize((WindowResizeEvent&) e);
			break;
		}

		CS_CORE_TRACE(e.ToString().c_str());
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& e)
	{
		glViewport(0, 0, m_Window->m_Data.Width, m_Window->m_Data.Height);
		return true;
	}
}