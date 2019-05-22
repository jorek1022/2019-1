//  2019 03 17 SUN
//  이로제
////// main.cpp

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

int main(void)
{
    GLFWwindow* window;
 
    // Initialize GLFW library
    if (!glfwInit())
        return -1;

     // Create a GLFW window containing a OpenGL context
    window = glfwCreateWindow(800, 800, "RoJE LEE", NULL, NULL);
    if(!window)
    {
        glfwTerminate();
        return -1;
    }

    // Make the current OpenGL context as one in the window
    glfwMakeContextCurrent(window);

    // Initialize GLEW library
    if (glewInit() != GLEW_OK)
        std::cout << "GLEW Init Error!" << std::endl;

    // Print out the OpenGL version supported by the graphics card in my PC
    std::cout << glGetString(GL_VERSION) << std::endl;

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        // Render here
        glClearColor(1, 1, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}
