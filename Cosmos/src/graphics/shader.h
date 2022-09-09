#pragma once

#include <glad/glad.h>

#include "core/logger.h"
#include "math/maths.h"

namespace Cosmos
{
	class Shader
	{
		int m_ProgramID, m_VertShaderID, m_FragShaderID;

		int Create(std::string srcPath, int type) const;
		void BindAttrib(int attribute, const char* variableName) const;
	public:
		Shader(std::string vertPath, std::string fragPath);

		void Start() const;
		void Stop() const;
		void Clean() const;

		int GetUniformLocation(std::string uniformName) const;

		void LoadFloat(int location, const float& value) const;
		void LoadBoolean(int location, const bool& value) const;
		void LoadVec3(int location, const cml::vec3& vector) const;
		void LoadMatrix(int location, const cml::mat4& matrix) const;
	};

	class StaticShader : public Shader
	{
	public:
		StaticShader()
			: Shader("shader.vert", "shader.frag") { }
	};
}