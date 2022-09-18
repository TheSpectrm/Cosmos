#include <cspch.h>
#include "graphics/vertex_buffer.h"

namespace Cosmos
{
	VertexBuffer::VertexBuffer(std::vector<float> vertices)
	{
		glGenBuffers(1, &Id);
		Bind();

		float* data = &vertices[0];
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(), data, GL_STATIC_DRAW);

		CORE_INFO("Generated Vertex Buffer Object (VBO) (id=%d)", Id);
	}

	void VertexBuffer::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, Id);
	}

	void VertexBuffer::Unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void VertexBuffer::Delete() const
	{
		CORE_TRACE("Deleting Vertex Buffer Object (VBO) (id=%d)", Id);
		glDeleteBuffers(1, &Id);
	}
}