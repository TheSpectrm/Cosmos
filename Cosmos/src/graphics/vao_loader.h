#pragma once

#include <GLAD/glad.h>

namespace Cosmos
{
	struct Model
	{
	private:
		int m_VaoID;
		size_t m_VertexCount;
	public:
		Model(int vaoID, size_t vertexCount)
			: m_VaoID(vaoID), m_VertexCount(vertexCount) { }

		int GetVaoID() const;
		size_t GetVertexCount() const;
	};

	class VAOLoader
	{
		std::vector<int> m_Vaos;
		std::vector<int> m_Vbos;

		int CreateVAO();
		void UnbindVAO() const;
		void StoreAttrib(int attribute, std::vector<float> data);
		void BindIndexBuffer(std::vector<int> indices);
	public:
		VAOLoader() = default;

		Model* LoadToVAO(std::vector<float> coords, std::vector<int> indices);
		void Clean() const;
	};
}