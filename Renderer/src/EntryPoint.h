#pragma once

extern Renderer::Application* Renderer::CreateApplication();

int main(int argc, char** argv)
{
	Renderer::Log::Init();
	LOGW("Logger is initialized");
	//int a = 5;
	//LOGI("Hello! Var={0}", a);

	auto app = Renderer::CreateApplication();
	app->Run();
	delete app;
}