#include "SandboxLayer.h"

using namespace GLCore;
using namespace GLCore::Utils;

SandboxLayer::SandboxLayer()
{
	mBufferSize = 0;
	mAttribComponentNum = 0;
}

SandboxLayer::~SandboxLayer()
{
}

void SandboxLayer::OnAttach()
{
	EnableGLDebugging();

	// Init here
	
	mShader = Shader::FromGLSLTextFiles(
		"assets/shaders/test.vert.glsl",
		"assets/shaders/test.frag.glsl"
	);

	mAttribComponentNum = 2;
	mBufferSize = 8;
	mIndeciesSize = 6;
	float positions[] = {
		-0.5f, -0.5f,
		 0.5f, -0.5f,
		 0.5f,  0.5f,
		-0.5f,  0.5f,
	};

	unsigned int indecies[] = {
		0, 1, 2,
		2, 3, 0
	};

	glGenBuffers(1, &mTriangleVB);	// 1 - number of buffers
	// buffer is generated, now we need to select it.
	glBindBuffer(GL_ARRAY_BUFFER, mTriangleVB);	// first argument - what is the purpose of usage
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

	glGenBuffers(1, &mTriangleIB);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mTriangleIB);	// first argument - what is the purpose of usage
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indecies), indecies, GL_STATIC_DRAW);


	// 0 - index of attribute (now we have only 1 attrbute)
	// 2 - component count, how many floats represent this specific vertex attribute.
	// stride in bytes, defines 'distance' to next vertex (not next attribute)
	// 0 - pointer-offset to attribute
	glEnableVertexAttribArray(0);	// ??? 0
	glVertexAttribPointer(0, mAttribComponentNum, GL_FLOAT, GL_FALSE, sizeof(float) * mAttribComponentNum, 0);

	glUseProgram(mShader->GetRendererID());

	int location = glGetUniformLocation(mShader->GetRendererID(), "uColor");
	ASSERT(location != (-1));		// ???
	glUniform4f(location, 1.0, 0.0, 0.0, 1.0);
}

void SandboxLayer::OnDetach()
{
	// Shutdown here

	glDeleteBuffers(1, &mTriangleVB);
}

void SandboxLayer::OnEvent(Event& event)
{
	// Events here
}

void SandboxLayer::OnUpdate(Timestep ts)
{
	// Render here
	
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//glUseProgram(mShader->GetRendererID());

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
	//LOG_INFO("color = {0} - {1} - {2} - {3}", color[0], color[1], color[2], color[3]);
	int location = glGetUniformLocation(mShader->GetRendererID(), "uColor");
	ASSERT(location != (-1));
	glUniform4f(location, color[0], color[1], color[2], color[3]);

	// If we have NO Index Buffer
	//glDrawArrays(GL_TRIANGLES, 0, mBufferSize / mAttribComponentNum);

	// TODO: If we HAVE Index Buffer
	GLcall(glDrawElements(GL_TRIANGLES, mIndeciesSize, GL_UNSIGNED_INT, nullptr));
}

void SandboxLayer::OnImGuiRender()
{
	// ImGui here

}
