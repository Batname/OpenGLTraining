#ifndef Widget_hpp
#define Widget_hpp

#include <stdio.h>
#include <vector>
#include <iostream>

class Widget
{
public:
    Widget();
    ~Widget();
    
    virtual void Show();
    class OpenGLWindow* GetOpenGLWindow();
    
    void RegisterActor(class Actor* actor);
    std::vector<class Actor*> GetActors();
protected:
    virtual void Render();
    virtual void KeyCallback(int key, int scancode, int action, int mode);
private:
    
    friend class OpenGLWindow;
    
    std::vector<class Actor*> Actors;
};

#endif /* Widget_hpp */
