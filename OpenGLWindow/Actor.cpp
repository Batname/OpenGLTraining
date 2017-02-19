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

Actor::Actor(Widget* ParentWidget) : ParentWidget(ParentWidget)
{
    // Register actor
    OpenGLWindow::RegisterActor(this, ParentWidget);
}

Actor::~Actor()
{
}

void Actor::Begin()
{
}

void Actor::Tick(float DeltaTime)
{
}
