#pragma once

#include <GLCore/Renderer/Renderer.h>
#include <GLRenderUtils.h>

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
	GLCore::Render::Texture* mTexture = nullptr;
	std::unique_ptr<GLCore::Render::Renderer> mRenderer;

	GLCore::Utils::OrthographicCameraController mCameraController;
	GLCore::Utils::Shader* mShader = nullptr;
	GLCore::Utils::VertexArray* mVertexArray = nullptr;
	GLCore::Utils::VertexBuffer* mVertexBuffer = nullptr;
	GLCore::Utils::IndexBuffer* mIndexBuffer = nullptr;
};