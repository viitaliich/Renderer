#include "SandboxLayer.h"

using namespace GLCore;
using namespace GLCore::Utils;
using namespace GLCore::Render;


SandboxLayer::SandboxLayer()
	: mCameraController(16.0f / 9.0f, true)
	//: mCameraController(1.0f / 1.0f, true)
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

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	mShader = Shader::FromGLSLTextFiles(
		"assets/shaders/test.vert.glsl",
		"assets/shaders/test.frag.glsl"
	);

	// x, y, tex_x, tex_y
	float positions[] = {
		-0.5f, -0.5f, 0.0f, 0.0f,
		 0.5f, -0.5f, 1.0f, 0.0f,
		 0.5f,  0.5f, 1.0f, 1.0f,
		-0.5f,  0.5f, 0.0f, 1.0f
	};

	/*float positions[] = {
		-10.5f, -10.5f, 0.0f, 0.0f,
		 10.5f, -10.5f, 1.0f, 0.0f,
		 10.5f,  10.5f, 1.0f, 1.0f,
		-10.5f,  10.5f, 0.0f, 1.0f
	};*/

	const unsigned int indecies[] = {
		0, 1, 2,
		2, 3, 0
	};

	//std::string texturePath = "C:\\dev\\Renderer\\OpenGL-Sandbox\\assets\\texturesPettern_mod.png";
	std::string texturePath = "assets/textures/Pettern_mod.png";
	mTexture = new Texture(texturePath);
	int slot = 0;
	mTexture->Bind(slot);
	mShader->SetUniform1i("uTexture", slot);

	mVertexBuffer = new VertexBuffer(positions, sizeof(positions));
	
	mVertexArray = new VertexArray();
	VertexBufferLayout layout;
	layout.Push<float>(2);	// points
	layout.Push<float>(2);	// texture
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
	
	mTexture->Unbind();
	delete mTexture;
}

void SandboxLayer::OnEvent(Event& event)
{
	// Events here
	mCameraController.OnEvent(event);

}

void SandboxLayer::OnUpdate(Timestep ts)
{
	// Render here
	
	mCameraController.OnUpdate(ts);

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
	/*mShader->SetUniformMat4f("uMVP", mCameraController.GetCamera().GetViewProjectionMatrix());
    mCameraController.GetCamera().Set().*/

	// If we have NO Index Buffer
	//glDrawArrays(GL_TRIANGLES, 0, mBufferSize / mAttribComponentNum);

	// If we HAVE Index Buffer
	mRenderer->Draw(mVertexArray, mIndexBuffer, mShader);
}

void SandboxLayer::OnImGuiRender()
{
	// ImGui here

    /*bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);*/

    {
        //static float f = 0.0f;
        //static int counter = 0;

        //ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

        //ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
        //ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
        //ImGui::Checkbox("Another Window", &show_another_window);

        //ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
        //ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

        //if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
        //    counter++;
        //ImGui::SameLine();
        //ImGui::Text("counter = %d", counter);

        //ImGuiIO io = ImGui::GetIO();
        //ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
        //ImGui::End();

        glm::vec3 newPosition;
        newPosition.x = mCameraController.GetCamera().GetPosition().x + mTranslation.x;
        newPosition.y = mCameraController.GetCamera().GetPosition().y + mTranslation.y;
        newPosition.z = mCameraController.GetCamera().GetPosition().z + mTranslation.z;

        mCameraController.GetCamera().SetPosition(newPosition);
        mShader->SetUniformMat4f("uMVP", mCameraController.GetCamera().GetViewProjectionMatrix());

        ImGui::SliderFloat3("Translation", &mTranslation.x, 0.0f, 2.0f);

        ImGuiIO io = ImGui::GetIO();
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
        //ImGui::End();
    }

}
