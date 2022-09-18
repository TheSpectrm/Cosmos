#include <cspch.h>
#include "graphics/vertex_array.h"

namespace Cosmos
{
	VertexArray::VertexArray()
	{	
		glGenVertexArrays(1, &Id);
		CORE_INFO("Generated Vertex Array Object (VAO) (id=%d)", Id);
	}

	void VertexArray::StoreAttrib(VertexBuffer buffer) const
	{
		buffer.Bind();
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, null);
		glEnableVertexAttribArray(0);
		buffer.Unbind();
	}

	void VertexArray::Bind() const
	{
		glBindVertexArray(Id);
	}

	void VertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

	void VertexArray::Delete() const
	{
		CORE_TRACE("Deleting Vertex Array Object (VAO) (id=%d)", Id);
		glDeleteVertexArrays(1, &Id);
	}
}