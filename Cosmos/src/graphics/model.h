/* MODEL (DATA TYPE) IMPLEMENTATION */
#pragma once

#include "core/csdefs.h"
#include "graphics/vertex_array.h"

namespace Cosmos
{
	class CS_API Model
	{
		int m_VertexCount = 0;

		VertexArray m_VertexArray;
		VertexBuffer m_VertexBuffer;
		IndexBuffer m_IndexBuffer;
	public:
		Model(std::vector<float> vertices, std::vector<uint16_t> indices);

		void Render() const;
		void Destroy() const;
	};
}