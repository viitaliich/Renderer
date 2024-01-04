#include "pch.h"

#include "Application.h"
#include "Logging/Log.h"

namespace Renderer {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		LOGI("Hello, World! Core Application");
		while (true);
	}
}