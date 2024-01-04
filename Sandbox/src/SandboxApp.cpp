#include "pch.h"

#include <Renderer.h>

class Sandbox : public Renderer::Application
{
public:
	Sandbox()
	{
		LOGI("Sandbox App Constructor");
	}

	~Sandbox()
	{

	}

};

Renderer::Application* Renderer::CreateApplication()
{
	return new Sandbox();
}