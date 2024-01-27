#include "pch.h"

#include <glad/glad.h>

#include "Application.h"


namespace Renderer {

	Application::Application()
	{
        mWindow = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
        while (mRunning)
        {
            glClear(GL_COLOR_BUFFER_BIT);
            glClearColor(0, 0, 0, 0);
            mWindow->OnUpdate();
        }
	}
}