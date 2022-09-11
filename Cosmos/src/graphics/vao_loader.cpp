#include <cspch.h>
#include "graphics/vao_loader.h"

namespace Cosmos
{
	uint32_t Model::GetVaoID() const
	{
		return m_VaoID;
	}

	size_t Model::GetVertexCount() const
	{
		return m_VertexCount;
	}

	int VAOLoader::CreateVAO()
	{
		uint32_t vaoID;
		glGenVertexArrays(1, &vaoID);
		glBindVertexArray(vaoID);
		m_Vaos.push_back(vaoID);

		CS_CORE_INFO("Generated Vertex Array Object (VAO) (id=%d)", vaoID);

		return vaoID;
	}

	void VAOLoader::StoreAttrib(int attribute, std::vector<float> data)
	{
		uint32_t vboID;
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
		uint32_t vboID;
		glGenBuffers(1, &vboID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboID);
		m_Vbos.push_back(vboID);

		CS_CORE_INFO("Generated Vertex Buffer Object (VBO) (id=%d)", vboID);

		int* buffer = &indices[0];
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * indices.size(), buffer, GL_STATIC_DRAW);
	}

	Model* VAOLoader::LoadToVAO(std::vector<float> coords, std::vector<int> indices)
	{
		uint32_t vaoID = CreateVAO();
		BindIndexBuffer(indices);
		StoreAttrib(0, coords);
		glBindVertexArray(0);

		return new Model(vaoID, indices.size());
	}

	void VAOLoader::Clean() const
	{
		for (uint32_t vao : m_Vaos)
		{
			CS_CORE_TRACE("Deleting Vertex Array Object (VAO) (id=%d)", vao);
			glDeleteVertexArrays((GLsizei) m_Vaos.size(), &vao);
		}
		for (uint32_t vbo : m_Vbos)
		{
			CS_CORE_TRACE("Deleting Vertex Buffer Object (VBO) (id=%d)", vbo);
			glDeleteBuffers((GLsizei) m_Vbos.size(), &vbo);
		}
	}
}