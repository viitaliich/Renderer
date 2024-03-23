#pragma once

#include <glad/glad.h>

#include "GLCore/Core/Log.h"

#ifdef GLCORE_PLATFORM_WINDOWS
	#define ASSERT(x) if(!(x)) __debugbreak();
#else
	#define ASSERT(x) if(!(x)) throw;
#endif

#define GLcall(x) GLclearError();x;ASSERT(GLlogCall())

static void GLclearError()
{
	while (glGetError() != GL_NO_ERROR);
}

static bool GLlogCall()
{
	while (GLenum error = glGetError())
	{
		LOG_ERROR("glError = {0}", error);
		return false;
	}
	return true;
}


namespace GLCore::Utils {

	enum class DebugLogLevel
	{
		None = 0, HighAssert = 1, High = 2, Medium = 3, Low = 4, Notification = 5
	};

	void EnableGLDebugging();
	void SetGLDebugLogLevel(DebugLogLevel level);
	void OpenGLLogMessage(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);

}