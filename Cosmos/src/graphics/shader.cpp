#include <cspch.h>
#include "graphics/shader.h"

namespace Cosmos
{
	#define CS_SHADER_TYPE(type) type == GL_VERTEX_SHADER ? "Vertex" : "Fragment"

	int Shader::Create(std::string srcFile, int type) const
	{
		const char* srcText;
		std::string str, line, path = __FILE__;

		#ifdef CS_BUILD_MSVC
		path = path.substr(0, path.find_last_of("\\") + 1) + "shaders\\" + srcFile;

		#elif defined(CS_BUILD_MINGW)
		path = "..\\..\\Cosmos\\src\\graphics\\shaders\\" + srcFile;
		#endif

		std::ifstream file(path);
		CS_CORE_TRACE("Reading shader source (GLSL) file: %s", path.c_str());

		while (std::getline(file, line))
			str += (line + "\n");

		srcText = str.c_str();

		int compiled, shaderID = glCreateShader(type);
		glShaderSource(shaderID, 1, &srcText, null);
		glCompileShader(shaderID);
		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compiled);

		if (!compiled)
		{
			int length;
			glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &length);

			std::vector<char> error(length);

			glGetShaderInfoLog(shaderID, length, &length, &error[0]);

			CS_CORE_ERROR("Could not compile shader");
			CS_CORE_ERROR("GLSL Error: %s", &error[0]);

			Clean();
			return 0;
		}

		CS_CORE_INFO("Created OpenGL %s shader (id=%d)", CS_SHADER_TYPE(type), shaderID);

		return shaderID;
	}

	void Shader::BindAttrib(int attribute, const char* variableName) const
	{
		glBindAttribLocation(m_ProgramID, attribute, variableName);
	}

	Shader::Shader(std::string vertPath, std::string fragPath)
	{
		m_VertShaderID = Create(vertPath, GL_VERTEX_SHADER);
		m_FragShaderID = Create(fragPath, GL_FRAGMENT_SHADER);
		m_ProgramID = glCreateProgram();

		glAttachShader(m_ProgramID, m_VertShaderID);
		glAttachShader(m_ProgramID, m_FragShaderID);
		BindAttrib(0, "position");

		glLinkProgram(m_ProgramID);
		glValidateProgram(m_ProgramID);
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
		CS_CORE_TRACE("Detaching and deleting vertex shader and fragment shader...");
		glDetachShader(m_ProgramID, m_VertShaderID);
		glDetachShader(m_ProgramID, m_FragShaderID);
		glDeleteShader(m_VertShaderID);
		glDeleteShader(m_FragShaderID);
		glDeleteProgram(m_ProgramID);
	}

	int Shader::GetUniformLocation(std::string uniformName) const
	{
		return glGetUniformLocation(m_ProgramID, uniformName.c_str());
	}

	void Shader::LoadFloat(int location, float value) const
	{
		glUniform1f(location, value);
	}

	void Shader::LoadBoolean(int location, bool value) const
	{
		glUniform1f(location, value ? 1.0f : 0.0f);
	}

	void Shader::LoadVector(int location, cml::vec3 vector) const
	{
		glUniform3f(location, vector.x, vector.y, vector.z);
	}

	void Shader::LoadMatrix(int location, cml::mat4 matrix) const
	{
		glUniformMatrix4fv(location, 1, GL_FALSE, matrix.m);
	}	
}