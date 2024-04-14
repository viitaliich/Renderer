#pragma once

#include <GLCore/Renderer/Renderer.h>

class SandboxLayer : public GLCore::Layer
{
public:
	SandboxLayer();
	virtual ~SandboxLayer();

	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnEvent(GLCore::Event& event) override;
	virtual void OnUpdate(GLCore::Timestep ts) override;
	virtual void OnImGuiRender() override;
private:
	GLCore::Utils::Shader* mShader = nullptr;
	//GLCore::Utils::OrthographicCameraController m_CameraController;
	
	std::unique_ptr<GLCore::Render::Renderer> mRenderer;

	GLCore::Utils::VertexArray* mVertexArray = nullptr;
	GLCore::Utils::VertexBuffer* mVertexBuffer = nullptr;
	GLCore::Utils::IndexBuffer* mIndexBuffer = nullptr;
};