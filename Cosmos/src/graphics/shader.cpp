#include <cspch.h>
#include "graphics/shader.h"

namespace Cosmos
{
	#define SHADER_TYPE(type) type == GL_VERTEX_SHADER ? "Vertex" : "Fragment"

	uint32_t Shader::Create(const std::string& srcFile, int type) const
	{
		const char* cSrc;
		std::string src, line, path = __FILE__;

		#ifdef BUILD_MSVC
		path = path.substr(0, path.find_last_of("\\") + 1) + "..\\..\\res\\shaders\\" + srcFile;
		#elif defined(BUILD_MINGW)
		path = "..\\..\\Cosmos\\res\\shaders\\" + srcFile;
		#endif

		std::ifstream file(path);
		CORE_TRACE("Reading shader source (GLSL) file: %s", path.c_str());

		while (std::getline(file, line))
			src += (line + "\n");

		cSrc = src.c_str();
		
		uint32_t shaderId = glCreateShader(type);
		glShaderSource(shaderId, 1, &cSrc, null);
		glCompileShader(shaderId);

		CheckError(shaderId, SHADER_TYPE(type));

		return shaderId;
	}

	void Shader::SetVariableByAttrib(uint8_t attribute, const std::string& variableName) const
	{
		glBindAttribLocation(m_ProgId, attribute, variableName.c_str());
	}

	void Shader::CheckError(uint32_t shaderId, const std::string& type) const
	{
		int success, length;
		glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &length);

		char* log = new char[length];

		if (type != "PROGRAM")
		{
			glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);

			if (!success)
			{
				glGetShaderInfoLog(shaderId, length, &length, &log[0]);
				CORE_ERROR("Could not compile shader");
				CORE_ERROR("GLSL Error: %s", &log[0]);
			} else {
				CORE_INFO("Created OpenGL %s shader (id=%d)", type.c_str(), shaderId);
			}
		} else {
			glGetShaderiv(shaderId, GL_LINK_STATUS, &success);

			if (!success)
			{
				glGetShaderInfoLog(shaderId, length, &length, &log[0]);
				CORE_ERROR("Could not link shaders");
				CORE_ERROR("GLSL Error: %s", &log[0]);
			} else {
				CORE_INFO("Created OpenGL shader %s (id=%d)", type.c_str(), shaderId);
			}
		}
	}

	Shader::Shader(const std::string& vertPath, const std::string& fragPath)
	{
		m_VertId = Create(vertPath, GL_VERTEX_SHADER);
		m_FragId = Create(fragPath, GL_FRAGMENT_SHADER);
		m_ProgId = glCreateProgram();

		glAttachShader(m_ProgId, m_VertId);
		glAttachShader(m_ProgId, m_FragId);
		SetVariableByAttrib(0, "position");

		glLinkProgram(m_ProgId);
		
		CheckError(m_ProgId, "PROGRAM");

		glDeleteShader(m_VertId);
		glDeleteShader(m_FragId);
	}

	void Shader::Start() const
	{
		glUseProgram(m_ProgId);
	}

	void Shader::Stop() const
	{
		glUseProgram(0);
	}

	void Shader::Clean() const
	{
		Stop();
		CORE_TRACE("Detaching and deleting vertex shader, fragment shader and shader program...");
		glDeleteShader(m_VertId);
		glDeleteShader(m_FragId);
		glDeleteProgram(m_ProgId);
	}

	uint32_t Shader::GetUniformLocation(const std::string& uniformName) const
	{
		return glGetUniformLocation(m_ProgId, uniformName.c_str());
	}

	void Shader::SetMat4(int location, const Cml::Mat4& matrix) const
	{
		glUniformMatrix4fv(location, 1, GL_FALSE, matrix.M);
	}	
}