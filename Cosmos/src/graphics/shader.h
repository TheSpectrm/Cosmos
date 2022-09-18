/* SHADER IMPLEMENTATION */
#pragma once

#include <glad/glad.h>

#include "core/csdefs.h"
#include "math/cml.h"

namespace Cosmos
{
	class Shader
	{
		uint32_t m_ProgId, m_VertId, m_FragId;

		uint32_t Create(const std::string& srcPath, int type) const;
		void SetVariableByAttrib(uint8_t attribute, const std::string& variableName) const;
		void CheckError(uint32_t shaderId, const std::string& type) const;
	public:
		Shader(const std::string& vertPath, const std::string& fragPath);

		void Start() const;
		void Stop() const;
		void Clean() const;

		uint32_t GetUniformLocation(const std::string& uniformName) const;
		void SetMat4(int location, const Cml::Mat4& matrix) const;
	};

	class StaticShader : public Shader
	{
	public:
		StaticShader()
			: Shader("shader.vert", "shader.frag") { }
	};
}