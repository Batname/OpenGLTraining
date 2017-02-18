#include "OpenGLWindow.hpp"
#include "Widget.hpp"

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
    printf("parent Widget Render\n");

}
