#pragma once

#include <glad/glad.h>

namespace Cosmos
{
	struct Model
	{
	private:
		uint32_t m_VaoID;
		size_t m_VertexCount;
	public:
		Model(int vaoID, size_t vertexCount)
			: m_VaoID(vaoID), m_VertexCount(vertexCount) { }

		uint32_t GetVaoID() const;
		size_t GetVertexCount() const;
	};

	class VAOLoader
	{
		std::vector<uint32_t> m_Vaos;
		std::vector<uint32_t> m_Vbos;

		int CreateVAO();
		void StoreAttrib(int attribute, std::vector<float> data);
		void BindIndexBuffer(std::vector<int> indices);
	public:
		VAOLoader() = default;

		Model* LoadToVAO(std::vector<float> coords, std::vector<int> indices);
		void Clean() const;
	};
}