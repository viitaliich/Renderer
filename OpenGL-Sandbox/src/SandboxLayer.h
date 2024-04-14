#pragma once

//#include <GLCore.h>
//#include <GLCoreUtils.h>
#include <GLCore/Util/Renderer.h>

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
	
	// include Renderer ???
	std::unique_ptr<Renderer> mRenderer;

	VertexArray* mVertexArray = nullptr;
	VertexBuffer* mVertexBuffer = nullptr;
	IndexBuffer* mIndexBuffer = nullptr;
};