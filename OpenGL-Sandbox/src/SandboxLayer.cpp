#include "SandboxLayer.h"

using namespace GLCore;
using namespace GLCore::Utils;

SandboxLayer::SandboxLayer()
{
}

SandboxLayer::~SandboxLayer()
{
	delete mVertexBuffer;
	delete mIndexBuffer;
	delete mVertexArray;
}

void SandboxLayer::OnAttach()
{
	EnableGLDebugging();

	// Init here
	
	mShader = Shader::FromGLSLTextFiles(
		"assets/shaders/test.vert.glsl",
		"assets/shaders/test.frag.glsl"
	);

	float positions[] = {
		-0.5f, -0.5f,
		 0.5f, -0.5f,
		 0.5f,  0.5f,
		-0.5f,  0.5f,
	};

	const unsigned int indecies[] = {
		0, 1, 2,
		2, 3, 0
	};

	mVertexBuffer = new VertexBuffer(positions, sizeof(positions));
	
	mVertexArray = new VertexArray();
	VertexBufferLayout layout;
	layout.Push<float>(2);
	mVertexArray->AddBuffer(mVertexBuffer, layout);

	mIndexBuffer = new IndexBuffer(indecies, 6);

	mRenderer = std::make_unique<Renderer>();
}

void SandboxLayer::OnDetach()
{
	// Shutdown here
	
	mVertexArray->Unbind();
	mVertexBuffer->Unbind();
	mIndexBuffer->Unbind();
	mShader->Unbind();
}

void SandboxLayer::OnEvent(Event& event)
{
	// Events here
}

void SandboxLayer::OnUpdate(Timestep ts)
{
	// Render here
	
	mRenderer->Clear(0.1f, 0.1f, 0.1f, 1.0f);

	static std::vector<float>color = { 0.0, 0.0, 0.0, 1.0 };
	static std::vector<float> increment = { 0.0001f, 0.001f, 0.01f };

	for (int i = 0; i < increment.size(); i++)
	{
		color[i] += increment[i];
	}

	for (int i = 0; i < increment.size(); i++)
	{
		if (color[i] > 1.0 || color[i] < 0.0)
		{
			increment[i] = -increment[i];
		}
	}
	mShader->SetUniform4f("uColor", color[0], color[1], color[2], color[3]);


	// If we have NO Index Buffer
	//glDrawArrays(GL_TRIANGLES, 0, mBufferSize / mAttribComponentNum);

	// If we HAVE Index Buffer
	mRenderer->Draw(mVertexArray, mIndexBuffer, mShader);
}

void SandboxLayer::OnImGuiRender()
{
	// ImGui here

}
