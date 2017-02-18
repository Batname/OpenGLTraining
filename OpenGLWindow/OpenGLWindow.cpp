#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

#include "OpenGLWindow.hpp"
#include "Widget.hpp"

std::vector<Widget*> OpenGLWindow::Widgets = {};

OpenGLWindow::OpenGLWindow()
{
    if (!glfwInit()) ErrorExit("glfwInit() in main()");
    
    Window = glfwCreateWindow(640, 480, "Hello GLFWwindow", NULL, NULL);
    if (!Window) ErrorExit("glfwCreateWindow() in main()");
    
        glfwMakeContextCurrent(Window);
}

OpenGLWindow::~OpenGLWindow()
{
    glfwTerminate();
}

int OpenGLWindow::exec()
{
    while (!glfwWindowShouldClose(Window)) {
        glfwSwapBuffers(Window);
        
        for(Widget* Val : OpenGLWindow::Widgets)
        {
            Val->Render();
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
