#pragma once

#include <GLCore.h>
#include <GLCoreUtils.h>

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
	int mBufferSize;
	int mIndeciesSize;
	int mAttribComponentNum;

	GLCore::Utils::Shader* mShader;
	GLCore::Utils::OrthographicCameraController m_CameraController;

	GLuint mTriangleVB, mTriangleIB;
	//GLuint mTriangleVA;
};