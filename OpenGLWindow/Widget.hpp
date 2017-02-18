#ifndef Widget_hpp
#define Widget_hpp

#include <stdio.h>

class Widget
{
public:
    Widget();
    ~Widget();
    
    virtual void Show();
protected:
    virtual void Render();
private:
    
    friend class OpenGLWindow;
};

#endif /* Widget_hpp */
