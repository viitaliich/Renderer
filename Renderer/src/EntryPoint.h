#pragma once

extern Renderer::Application* Renderer::CreateApplication();

int main(int argc, char** argv)
{
	Renderer::Log::Init();
	LOGW("Logger is initialized");

	auto app = Renderer::CreateApplication();
	app->Run();
	delete app;
}