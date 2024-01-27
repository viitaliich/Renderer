#include "pch.h"
#include "WindowsWindow.h"

#include <glad/glad.h>


namespace Renderer {

	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		mData.title = props.title;
		mData.width = props.width;
		mData.height = props.height;

		LOGI("Creating window {0} ({1}, {2})", mData.title, mData.width, mData.height);

		if (!s_GLFWInitialized)
		{
			// TODO: glfwTerminate on system shutdown
			int success = glfwInit();
			if (!success) {
				LOGE("Could not intialize GLFW!");
				return;
			}

			s_GLFWInitialized = true;
		}

		mWindow = glfwCreateWindow((int)props.width, (int)props.height, mData.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(mWindow);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		if (!status)
		{
			glfwTerminate();
			LOGE("window is not created!");
			return;
		}
		glfwSetWindowUserPointer(mWindow, &mData);
		SetVSync(true);

		LOGI("OpenGL Info:");
		LOGI("  Vendor: {0}", (const char*)glGetString(GL_VENDOR));
		LOGI("  Renderer: {0}", (const char*)glGetString(GL_RENDERER));
		LOGI("  Version: {0}", (const char*)glGetString(GL_VERSION));
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(mWindow);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(mWindow);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		mData.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return mData.VSync;
	}
}