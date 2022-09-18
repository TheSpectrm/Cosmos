/* VERTEX BUFFER IMPLEMENTATION */
#pragma once

#include <glad/glad.h>
#include "core/csdefs.h"

namespace Cosmos
{
	struct VertexBuffer
	{
		uint32_t Id;

		VertexBuffer() = default;
		VertexBuffer(std::vector<float> vertices);

		void Bind() const;
		void Unbind() const;
		void Delete() const;
	};
}