
// OpenGL Function prototypes
#define GLEW_STATIC
#include <GL/glew.h>

// Handle window
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>

#include "OpenGLWindow.hpp"
#include "Widget.hpp"

std::vector<Widget*> OpenGLWindow::Widgets = {};

OpenGLWindow::OpenGLWindow()
{
    if (!glfwInit()) ErrorExit("glfwInit() in main()");
    // Optionally configure hints
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RELEASE, GL_FALSE);
    
    Window = glfwCreateWindow(640, 480, "Hello GLFWwindow", NULL, NULL);
    if (!Window) ErrorExit("glfwCreateWindow() in OpenGLWindow()");
    
    glfwMakeContextCurrent(Window);
    
    // Init Glew
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) ErrorExit("glewInit() in OpenGLWindow()");
    
    // Set viewport
    int Width, Height;
    glfwGetFramebufferSize(Window, &Width, &Height);
    glViewport(0, 0, Width, Height);
}

OpenGLWindow::~OpenGLWindow()
{
    glfwTerminate();
}

int OpenGLWindow::exec()
{
    while (!glfwWindowShouldClose(Window)) {
        glfwSwapBuffers(Window);
        
        for(Widget* widget : OpenGLWindow::Widgets)
        {
            widget->Render();
        }
        
        glfwPollEvents();
    }
    
    glfwTerminate();
    
    return 0;
}

void OpenGLWindow::ErrorExit(const char* Msg)
{
    printf("[ERROR] %s\n", Msg);
    glfwTerminate();
    exit(EXIT_FAILURE);
}

void OpenGLWindow::RegisterWidget(Widget* widget)
{
    OpenGLWindow::Widgets.push_back(widget);
}
