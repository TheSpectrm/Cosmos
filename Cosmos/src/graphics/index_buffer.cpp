#include <cspch.h>
#include "graphics/index_buffer.h"

namespace Cosmos
{
	IndexBuffer::IndexBuffer(std::vector<uint16_t> indices)
	{
		glGenBuffers(1, &Id);
		Bind();

		uint16_t* data = &indices[0];
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint16_t) * indices.size(), data, GL_STATIC_DRAW);

		CORE_INFO("Generated Element Buffer Object (EBO) (id=%d)", Id);
	}

	void IndexBuffer::Bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Id);
	}

	void IndexBuffer::Unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	void IndexBuffer::Delete() const
	{
		CORE_TRACE("Deleting Element Buffer Object (EBO) (id=%d)", Id);
		glDeleteBuffers(1, &Id);
	}
}