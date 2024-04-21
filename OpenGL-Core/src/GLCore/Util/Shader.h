#pragma once

#include <string>

#include <glad/glad.h>

namespace GLCore::Utils {

	class Shader
	{
	public:
		~Shader();

		static Shader* FromGLSLTextFiles(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
	
		GLuint GetRendererID() { return m_RendererID; }

		void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
		void SetUniform1i(const std::string& name, int value);
	
		void Bind() const;
		void Unbind() const;
	
	private:
		Shader() = default;

		void LoadFromGLSLTextFiles(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
		GLuint CompileShader(GLenum type, const std::string& source);
		unsigned int getUniformLocation(const std::string& name);
	private:
		GLuint m_RendererID;
		std::unordered_map<std::string, int> mUniformLocationCache;
	};

}