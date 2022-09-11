#pragma once

#include <glad/glad.h>

#include "math/maths.h"

namespace Cosmos
{
	class Shader
	{
		uint32_t m_ProgramID, m_VertShaderID, m_FragShaderID;

		uint32_t Create(std::string srcPath, int type) const;
		void BindAttrib(int attribute, const std::string& variableName) const;
	public:
		Shader(std::string vertPath, std::string fragPath);

		void Start() const;
		void Stop() const;
		void Clean() const;

		int GetUniformLocation(std::string uniformName) const;
		void LoadMatrix(int location, const cml::mat4& matrix) const;
	};

	class StaticShader : public Shader
	{
	public:
		StaticShader()
			: Shader("shader.vert", "shader.frag") { }
	};
}