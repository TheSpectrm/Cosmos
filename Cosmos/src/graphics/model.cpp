#include <cspch.h>
#include "graphics/model.h"

namespace Cosmos
{
	Model::Model(std::vector<float> vertices, std::vector<uint16_t> indices)
	{
		m_VertexCount = indices.size();

		m_VertexArray.Bind();
		m_VertexBuffer = VertexBuffer(vertices);
		m_IndexBuffer = IndexBuffer(indices);

		m_VertexArray.StoreAttrib(m_VertexBuffer);

		m_VertexArray.Unbind();
		m_VertexBuffer.Unbind();
		m_IndexBuffer.Unbind();
	}

	void Model::Render() const
	{
		m_VertexArray.Bind();
		glDrawElements(GL_TRIANGLES, (GLsizei) m_VertexCount, GL_UNSIGNED_SHORT, null);
	}

	void Model::Destroy() const
	{
		m_VertexArray.Delete();
		m_VertexBuffer.Delete();
		m_IndexBuffer.Delete();
	}
}