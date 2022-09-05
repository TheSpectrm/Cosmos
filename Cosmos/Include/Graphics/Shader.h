#pragma once

#include <GLAD/glad.h>
#include "Math/Maths.h"
#include "Core/Logger.h"

namespace Cosmos
{
	class Shader
	{
	public:
		Shader(std::string vertPath, std::string fragPath);

		void Start() const;
		void Stop() const;
		void Clean() const;

		void LoadFloat(int location, float value) const;
		void LoadVector(int location, csm::vec3 vector) const;
		void LoadBoolean(int location, bool value) const;
		void LoadMatrix(int location, csm::mat4 matrix) const;

		int GetUniformLocation(std::string uniformName) const;
	private:
		int Create(std::string srcPath, int type) const;
		void BindAttrib(int attribute, const char* variableName);

		int m_ProgramID, m_VertShaderID, m_FragShaderID;
	};

	class StaticShader : public Shader
	{
	public:
		StaticShader()
			: Shader("Shader.vert", "Shader.frag") { }
	};
}