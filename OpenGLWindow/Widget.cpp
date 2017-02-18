#include "OpenGLWindow.hpp"
#include "Widget.hpp"

OpenGLWindow* Widget::openGLWindow = nullptr;

Widget::Widget()
{
    OpenGLWindow::RegisterWidget(this);
}

Widget::~Widget()
{

}

void Widget::Show()
{
}

void Widget::Render()
{

}

void Widget::KeyCallback(int key, int scancode, int action, int mode)
{

    
}

OpenGLWindow* Widget::GetOpenGLWindow()
{
    return Widget::openGLWindow;
}
