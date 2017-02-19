//
//  Actor.hpp
//  OpenGLTraining
//
//  Created by bat on 2/19/17.
//  Copyright © 2017 batlab. All rights reserved.
//

#ifndef Actor_hpp
#define Actor_hpp

#include <stdio.h>

class Actor
{
public:
    Actor(class Widget* ParentWidget);
    ~Actor();
    
    virtual void Begin();
    virtual void Tick(float DeltaTime);
    
    void SetVertexShader(const char* vertexShader);
    void SetFragmentShader(const char* fragmentShader);
    
protected:
private:
    class Widget* ParentWidget;
    const char* VertexShaderPath;
    const char* FragmentShaderPath;
    class Shader* ActorShader;
    
    friend class Widget;
};

#endif /* Actor_hpp */
