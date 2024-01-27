#pragma once

#include "Window.h"

#include <GLFW/glfw3.h>

namespace Renderer {

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return mData.width; }
		inline unsigned int GetHeight() const override { return mData.height; }

		// Window attributes
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		GLFWwindow* mWindow;

		struct WindowData
		{
			std::string title;
			unsigned int width;
			unsigned int height;
			bool VSync;
		};

		WindowData mData;
	};
}
