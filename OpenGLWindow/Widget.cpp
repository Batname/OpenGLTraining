#include "OpenGLWindow.hpp"
#include "Widget.hpp"
#include "Actor.hpp"
#include "Shader.hpp"

#include <map>
#include <iostream>

Widget::Widget()
{
    OpenGLWindow::RegisterWidget(this);
}

Widget::~Widget()
{
    for (const auto &Val : Widget::Actors) {
        delete Val;
    }
}

void Widget::Show()
{
    // Render Shaders for each Actor
    for (const auto &Val : Actors) {
        
        // Render default Shader
        if (Val->VertexShaderPath == NULL || Val->FragmentShaderPath == NULL)
        {
            Val->ActorShader = new Shader(
            "/Volumes/SEAGATE/Mac/Projects/OpenGL/OpenGLTraining/OpenGLWindow/Shaders/vertex.glsl",
           "/Volumes/SEAGATE/Mac/Projects/OpenGL/OpenGLTraining/OpenGLWindow/Shaders/fragment.glsl"
           );
        } // Render custom shader
        else
        {
            Val->ActorShader = new Shader(Val->VertexShaderPath, Val->FragmentShaderPath);
        }

    }

    // Run Begin function for each Actor
}

void Widget::Render()
{
}

void Widget::KeyCallback(int key, int scancode, int action, int mode)
{

}

OpenGLWindow* Widget::GetOpenGLWindow()
{
    return OpenGLWindow::GetOpenGLWindow();
}

void Widget::RegisterActor(Actor* actor)
{
    
    Actors.push_back(actor);
}

std::vector<Actor*> Widget::GetActors()
{
    return Widget::Actors;
}
