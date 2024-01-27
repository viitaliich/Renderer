#pragma once

#include "Window/Window.h"

namespace Renderer {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		std::unique_ptr<Window> mWindow;
		bool mRunning = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}