//
//  Actor.cpp
//  OpenGLTraining
//
//  Created by bat on 2/19/17.
//  Copyright © 2017 batlab. All rights reserved.
//

#include <map>

#include "Actor.hpp"
#include "Widget.hpp"
#include "OpenGLWindow.hpp"
#include "Shader.hpp"

Actor::Actor(Widget* ParentWidget) : ParentWidget(ParentWidget)
{
    // Default properties
    VertexShaderPath = nullptr;
    FragmentShaderPath = nullptr;
}

Actor::~Actor()
{
    delete ActorShader;
}

void Actor::Begin()
{
}

void Actor::Tick(float DeltaTime)
{
}

void Actor::SetVertexShader(const char* vertexShader)
{
    VertexShaderPath = vertexShader;
}

void Actor::SetFragmentShader(const char* fragmentShader)
{
    FragmentShaderPath = fragmentShader;
}
