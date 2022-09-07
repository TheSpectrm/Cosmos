#include <cspch.h>
#include "graphics/vao_loader.h"

namespace Cosmos
{
	int Model::GetVaoID() const
	{
		return m_VaoID;
	}

	size_t Model::GetVertexCount() const
	{
		return m_VertexCount;
	}

	int VAOLoader::CreateVAO()
	{
		GLuint vaoID;
		glGenVertexArrays(1, &vaoID);
		glBindVertexArray(vaoID);
		m_Vaos.push_back(vaoID);

		CS_CORE_INFO("Generated Vertex Array Object (VAO) (id=%d)", vaoID);

		return vaoID;
	}

	void VAOLoader::UnbindVAO() const
	{
		glBindVertexArray(0);
	}

	void VAOLoader::StoreAttrib(int attribute, std::vector<float> data)
	{
		GLuint vboID;
		glGenBuffers(1, &vboID);
		glBindBuffer(GL_ARRAY_BUFFER, vboID);
		m_Vbos.push_back(vboID);

		CS_CORE_INFO("Generated Vertex Buffer Object (VBO) (id=%d)", vboID);

		float* buffer = &data[0];
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * data.size(), buffer, GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(attribute, 3, GL_FLOAT, GL_FALSE, 0, null);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	void VAOLoader::BindIndexBuffer(std::vector<int> indices)
	{
		GLuint vboID;
		glGenBuffers(1, &vboID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboID);
		m_Vbos.push_back(vboID);

		CS_CORE_INFO("Generated Vertex Buffer Object (VBO) (id=%d)", vboID);

		int* buffer = &indices[0];
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * indices.size(), buffer, GL_STATIC_DRAW);
	}

	Model* VAOLoader::LoadToVAO(std::vector<float> coords, std::vector<int> indices)
	{
		GLuint vaoID = CreateVAO();
		BindIndexBuffer(indices);
		StoreAttrib(0, coords);
		UnbindVAO();

		return new Model(vaoID, indices.size());
	}

	void VAOLoader::Clean() const
	{
		for (GLuint vao : m_Vaos) 
		{
			CS_CORE_TRACE("Deleting Vertex Array Object (VAO) (id=%d)", vao);
			glDeleteVertexArrays((GLsizei) m_Vaos.size(), &vao);
		}
		for (GLuint vbo : m_Vbos)
		{
			CS_CORE_TRACE("Deleting Vertex Buffer Object (VBO) (id=%d)", vbo);
			glDeleteBuffers((GLsizei) m_Vbos.size(), &vbo);
		}
	}
}