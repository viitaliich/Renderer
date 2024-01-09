#include "pch.h"

#include <Renderer.h>

class Sandbox : public Renderer::Application
{
public:
	Sandbox()
	{
		LOGI("Sandbox App Constructor");
		//int a = 5;
		//LOGI("Hello! Var={0}", a);
	}

	~Sandbox()
	{

	}

};

Renderer::Application* Renderer::CreateApplication()
{
	return new Sandbox();
}