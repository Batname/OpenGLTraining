#ifndef OpenGLWindow_hpp
#define OpenGLWindow_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

class OpenGLWindow
{
public:
    enum class EStatus
    {
        ERunning,
        EShouldClose
    };
    
public:
    OpenGLWindow();
    ~OpenGLWindow();
    
    int exec();
    
    /** Public instance method */
    void SetStatus(EStatus NewStatus);
    
    /** Static methods */
    static void RegisterWidget(class Widget* widget);
protected:
private:
    /** Props */
    struct GLFWwindow* Window;
    EStatus Status;
    
    /** Static props */
    static std::vector<class Widget*> Widgets;

    
    void ErrorExit(const char* Msg);
    void HandleState();
    
    /** Static func */
    static void KeyCallback(struct GLFWwindow* window, int key, int scancode, int action, int mode);
    
    friend class Widget;
};

#endif /* OpenGLWindow_hpp */
