/* INDEX BUFFER IMPLEMENTATION */
#pragma once

#include <glad/glad.h>
#include "core/csdefs.h"

namespace Cosmos
{
	struct IndexBuffer
	{
		uint32_t Id;

		IndexBuffer() = default;
		IndexBuffer(std::vector<uint16_t> indices);

		void Bind() const;
		void Unbind() const;
		void Delete() const;
	};
}