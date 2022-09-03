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
		m_VAOLoader = std::unique_ptr<VAOLoader>(new VAOLoader());
		m_Shader = std::unique_ptr<StaticShader>(new StaticShader());
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

		Model* model = m_VAOLoader->LoadToVAO(vertices, indices);

		vec2 va(3.0f, 3.0f);
		vec2 vb = va + vec2(2.0f, 2.0f);
		CS_CORE_TRACE(vb.ToString().c_str());

		vec3 vc(3.0f, 3.0f, 3.0f);
		vec3 vd = vc - vec3(2.0f, 2.0f, 2.0f);
		CS_CORE_TRACE(vd.ToString().c_str());

		vec4 ve(3.0f, 3.0f, 3.0f, 3.0f);
		vec4 vf = ve * vec4(2.0f, 2.0f, 2.0f, 2.0f);
		CS_CORE_TRACE(vf.ToString().c_str());

		m_Shader->Start();

		// Main program loop
		while (m_Running)
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glClearColor(0.1f, 0.1f, 0.1f, 0.0f);

			// Render the triangle model
			glBindVertexArray(model->m_VaoID);
			glDrawElements(GL_TRIANGLES, (GLsizei) model->m_VertexCount, GL_UNSIGNED_INT, null);

			m_Window->Update();
		}
	}

	void Application::Stop()
	{
		m_Running = false;
		m_VAOLoader->Clean();
		m_Shader->Clean();
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
		Stop();
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& e)
	{
		glViewport(0, 0, m_Window->m_Data.Width, m_Window->m_Data.Height);
		return true;
	}
}