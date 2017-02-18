#ifndef Widget_hpp
#define Widget_hpp

#include <stdio.h>

class Widget
{
public:
    Widget();
    ~Widget();
    
    virtual void Show();
    class OpenGLWindow* GetOpenGLWindow();
protected:
    virtual void Render();
    virtual void KeyCallback(int key, int scancode, int action, int mode);
private:
    
    friend class OpenGLWindow;
    
    static class OpenGLWindow* openGLWindow;
};

#endif /* Widget_hpp */
