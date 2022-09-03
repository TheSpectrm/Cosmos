#pragma once

#include <GLAD/glad.h>

namespace Cosmos
{
	class Shader
	{
	public:
		Shader(std::string vertPath, std::string fragPath);

		void Start() const;
		void Stop() const;
		void Clean() const;

		virtual void BindAttributes() { }
	private:
		int m_ProgramID, m_VertShaderID, m_FragShaderID;

		int Create(std::string srcPath, int type) const;
	protected:
		void BindAttribute(int attribute, const char* variableName);
	};

	class StaticShader : public Shader
	{
	public:
		StaticShader()
			: Shader("Shader.vert", "Shader.frag") { }

	protected:
		void BindAttributes() { BindAttribute(0, "position"); }
	};
}