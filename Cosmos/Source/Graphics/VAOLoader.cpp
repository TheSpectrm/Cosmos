#include <cspch.h>
#include "Graphics/VAOLoader.h"

namespace Cosmos
{
	Model* VAOLoader::LoadToVAO(std::vector<float> coords)
	{
		int vaoID = CreateVAO();
		StoreDataAttribute(0, coords);
		UnbindVAO();

		return new Model(vaoID, coords.size() / 3);
	}

	void VAOLoader::Clean() const
	{
		for (GLuint vao : m_Vaos)
			glDeleteVertexArrays(m_Vaos.size(), &vao);

		for (GLuint vbo : m_Vbos)
			glDeleteBuffers(m_Vbos.size(), &vbo);
	}

	int VAOLoader::CreateVAO()
	{
		GLuint vaoID;
		glGenVertexArrays(1, &vaoID);
		glBindVertexArray(vaoID);
		m_Vaos.push_back(vaoID);

		return vaoID;
	}

	void VAOLoader::UnbindVAO() const
	{
		glBindVertexArray(0);
	}

	void VAOLoader::StoreDataAttribute(int attrNumber, std::vector<float> data)
	{
		GLuint vboID;
		glGenBuffers(1, &vboID);
		glBindBuffer(GL_ARRAY_BUFFER, vboID);
		m_Vbos.push_back(vboID);

		float* buffer = &data[0];
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * data.size(), buffer, GL_STATIC_DRAW);
		glVertexAttribPointer(attrNumber, 3, GL_FLOAT, GL_FALSE, 0, null);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}