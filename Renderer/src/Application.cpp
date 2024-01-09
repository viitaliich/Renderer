#include "pch.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Application.h"
#include "Logging/Log.h"

namespace Renderer {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		LOGI("Hello, World! Core Application");

        GLFWwindow* window;

        /* Initialize the library */
        if (!glfwInit())
        {
            LOGE("glfw is not init!");
            return;
        }

        /* Create a windowed mode window and its OpenGL context */
        window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            LOGE("window is not created!");
            return;
        }

        /* Make the window's context current */
        glfwMakeContextCurrent(window);
        
        // Init GLAD
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        if (status != 1)
        {
            LOGE("glad status = {0}", status);
            return;
        }

        // Get OpenGL version
        LOGI("OpenGL Info:");
        LOGI("  Vendor: {0}", (const char*)glGetString(GL_VENDOR));
        LOGI("  Renderer: {0}", (const char*)glGetString(GL_RENDERER));
        LOGI("  Version: {0}", (const char*)glGetString(GL_VERSION));

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            /* Render here */
            glClear(GL_COLOR_BUFFER_BIT);

            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }
        LOGI("END");

        glfwTerminate();
	}
}