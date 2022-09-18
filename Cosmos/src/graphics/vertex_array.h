/* VERTEX ARRAY IMPLEMENTATION */
#pragma once

#include "core/csdefs.h"
#include "graphics/vertex_buffer.h"
#include "graphics/index_buffer.h"

namespace Cosmos
{
	struct VertexArray
	{
		uint32_t Id;

		VertexArray();

		void StoreAttrib(VertexBuffer buffer) const;

		void Bind() const;
		void Unbind() const;
		void Delete() const;
	};
}