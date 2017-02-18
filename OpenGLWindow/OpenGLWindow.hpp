#ifndef OpenGLWindow_hpp
#define OpenGLWindow_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

class OpenGLWindow
{
public:
    OpenGLWindow();
    ~OpenGLWindow();
    
    int exec();
    
    static void RegisterWidget(class Widget* widget);
protected:
private:
    /** Props */
    struct GLFWwindow* Window;
    
    /** Static props */
    static std::vector<class Widget*> Widgets;

    
    void ErrorExit(const char* Msg);
};

#endif /* OpenGLWindow_hpp */
