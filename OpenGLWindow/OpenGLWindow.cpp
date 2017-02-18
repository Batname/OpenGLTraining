
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
    glfwSetKeyCallback(Window, OpenGLWindow::KeyCallback);
    
    // Init Glew
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) ErrorExit("glewInit() in OpenGLWindow()");
    
    // Set viewport
    int Width, Height;
    glfwGetFramebufferSize(Window, &Width, &Height);
    glViewport(0, 0, Width, Height);
    
    // Set custom props
    SetStatus(EStatus::ERunning);
    
    // Inform widget about this pointer
    Widget::openGLWindow = this;
}

OpenGLWindow::~OpenGLWindow()
{
    glfwTerminate();
}

int OpenGLWindow::exec()
{
    // Program loop
    while (!glfwWindowShouldClose(Window)) {
        glfwSwapBuffers(Window);
        
        HandleState();
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

void OpenGLWindow::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    for(Widget* widget : OpenGLWindow::Widgets)
    {
        widget->KeyCallback(key, scancode, action, mode);
    }
}

void OpenGLWindow::SetStatus(EStatus NewStatus)
{
    Status = NewStatus;
}

void OpenGLWindow::HandleState()
{
    // Check statuses
    switch (Status) {
        case EStatus::EShouldClose:
            glfwSetWindowShouldClose(Window, GL_TRUE);
            break;
            
        case EStatus::ERunning:
            // ERunning
            break;
        default:
            break;
    }
}
