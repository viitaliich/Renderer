#pragma once

#include "pch.h"

namespace Renderer {

	struct WindowProps
	{
		std::string title;
		unsigned int width;
		unsigned int height;

		WindowProps(const std::string& title = "Demo",
			unsigned int width = 1920,
			unsigned int height = 1080)
			: title(title), width(width), height(height)
		{
		}
	};

	// Interface representing a desktop system based Window
	class Window
	{
	public:
		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attributes
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};

}