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
		m_VAOLoader->Clean();
		m_Shader->Clean();
	}

	void Application::OnEvent(Event& e)
	{
		switch (e.GetEventType())
		{
		case EventType::WindowClose:
			e.m_Handled = OnWindowClose((WindowCloseEvent&)e);
			break;

		case EventType::WindowResize:
			e.m_Handled = OnWindowResize((WindowResizeEvent&)e);
			break;
		}

		CS_CORE_TRACE(e.ToString().c_str());
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

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(new Window(SCALE * WIDTH, SCALE * HEIGHT, "Cosmos"));
		m_VAOLoader = std::unique_ptr<VAOLoader>(new VAOLoader());
		m_Shader = std::unique_ptr<StaticShader>(new StaticShader());
		CS_CORE_INFO("Created and initialized application");

		m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
	}

	void Application::Run() const
	{
		Model* model = m_VAOLoader->LoadToVAO({
			// Vertices
			-0.5f, 0.5f, 0.0f,
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			0.5f, 0.5f, 0.0f,
		}, {
			// Indices
			0, 1, 3,
			3, 1, 2
		});

		float x = -1.0f, y = -1.0f, z = 0.0f;
		float rotX = 0.0f, rotY = 0.0f, rotZ = 0.0f;
		float scale = 0.5f;
		
		// Main program loop
		while (m_Running)
		{
			x += 0.004f;
			y += 0.004f;
			rotY += 1.0f;
			rotZ += 1.0f;
			scale += 0.001;

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glClearColor(1 / 255.0f * 98, 1 / 255.0f * 172, 1 / 255.0f * 236, 1.0f);

			m_Shader->Start();
			glBindVertexArray(model->GetVaoID());

			cml::mat4 modelMatrix = cml::identity();
			modelMatrix *= cml::translate(cml::vec3(x, y, z));
			modelMatrix *= cml::rotate((float) rotY, cml::vec3(0.0f, 1.0f, 0.0f));
			modelMatrix *= cml::rotate((float) rotZ, cml::vec3(0.0f, 0.0f, 1.0f));
			modelMatrix *= cml::scale(cml::vec3(scale, scale, scale));

			m_Shader->LoadMatrix(m_Shader->GetUniformLocation("modelMatrix"), modelMatrix);
			glDrawElements(GL_TRIANGLES, (GLsizei) model->GetVertexCount(), GL_UNSIGNED_INT, null);
			m_Shader->Stop();

			m_Window->Update();
		}
	}
}