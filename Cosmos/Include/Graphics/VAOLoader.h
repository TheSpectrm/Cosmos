#pragma once

#include <glad/glad.h>

namespace Cosmos
{
	class Model
	{
	public:
		int m_VaoID, m_VertexCount;

		Model(int vaoID, int vertexCount)
			: m_VaoID(vaoID), m_VertexCount(vertexCount) { }
	};

	class VAOLoader
	{
		std::vector<int> m_Vaos;
		std::vector<int> m_Vbos;
	public:
		VAOLoader() = default;

		Model* LoadToVAO(std::vector<float> coords);
		void Clean() const;
	private:
		int CreateVAO();
		void UnbindVAO() const;
		void StoreDataAttribute(int attrNumber, std::vector<float> data);
	};
}