#include <cspch.h>
#include "Core/Logger.h"
#include "Graphics/Shader.h"

namespace Cosmos
{
	Shader::Shader(std::string vertPath, std::string fragPath)
	{
		m_VertShaderID = CreateShader(vertPath, GL_VERTEX_SHADER);
		m_FragShaderID = CreateShader(fragPath, GL_FRAGMENT_SHADER);
		m_ProgramID = glCreateProgram();

		glAttachShader(m_ProgramID, m_VertShaderID);
		glAttachShader(m_ProgramID, m_FragShaderID);
		glLinkProgram(m_ProgramID);
		glValidateProgram(m_ProgramID);

		BindAttributes();
	}

	void Shader::Start() const
	{
		glUseProgram(m_ProgramID);
	}

	void Shader::Stop() const
	{
		glUseProgram(0);
	}

	void Shader::Clean() const
	{
		Stop();
		glDetachShader(m_ProgramID, m_VertShaderID);
		glDetachShader(m_ProgramID, m_FragShaderID);
		glDeleteShader(m_VertShaderID);
		glDeleteShader(m_FragShaderID);
		glDeleteProgram(m_ProgramID);
	}

	void Shader::BindAttribute(int attribute, const char* variableName)
	{
		glBindAttribLocation(m_ProgramID, attribute, variableName);
	}

	int Shader::CreateShader(std::string srcFile, int type) const
	{
		const char* srcText;
		std::string str, line;
		std::ifstream file(srcFile);
		
		while (std::getline(file, line)) 
			str += (line + "\n");

		srcText = str.c_str();

		int compiled = false;
		int shaderID = glCreateShader(type);
		glShaderSource(shaderID, 1, &srcText, null);
		glCompileShader(shaderID);
		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compiled);

		if (!compiled) 
		{
			int length;
			glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH,	&length);

			std::vector<char> error(length);

			glGetShaderInfoLog(shaderID, length, &length, &error[0]);

			CS_CORE_ERROR("Could not compile shader");
			CS_CORE_ERROR("GLSL Error: %s", &error[0]);

			Clean();
			return 0;
		}

		return shaderID;
	}
}