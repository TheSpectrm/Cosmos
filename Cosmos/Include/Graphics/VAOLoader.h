#pragma once

#include <GLAD/glad.h>

namespace Cosmos
{
	struct Model
	{
		int m_VaoID;
		size_t m_VertexCount;

		Model(int vaoID, size_t vertexCount)
			: m_VaoID(vaoID), m_VertexCount(vertexCount) { }
	};

	class VAOLoader
	{
	public:
		VAOLoader() = default;

		Model* LoadToVAO(std::vector<float> coords, std::vector<int> indices);
		void Clean() const;
	private:
		int CreateVAO();
		void UnbindVAO() const;
		void BindIndexBuffer(std::vector<int> indices);
		void StoreAttrib(int attrNumber, std::vector<float> data);

		std::vector<int> m_Vaos;
		std::vector<int> m_Vbos;
	};
}