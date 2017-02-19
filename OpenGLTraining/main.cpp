#include <OpenGLWindow/OpenGLWindow.hpp>
#include <OpenGLWindow/Widget.hpp>
#include <OpenGLWindow/Actor.hpp>
#include <stdio.h>


class MyActor : public Actor
{
public:
    MyActor(Widget* ParentWidget = 0);
    ~MyActor();
protected:
private:
};

MyActor::MyActor(Widget* ParentWidget) :
    Actor(ParentWidget)
{
}
MyActor::~MyActor()
{

}

class MyWidget : public Widget
{
public:
    MyWidget();
    ~MyWidget();
protected:
    virtual void Render() override;
    virtual void KeyCallback(int key, int scancode, int action, int mode) override;
private:
};

MyWidget::MyWidget()
{
    MyActor* actor = new MyActor(this);
    RegisterActor(actor);
    // add actor to widget
}

MyWidget::~MyWidget()
{
}

void MyWidget::Render()
{
    // call parent
    Widget::Render();
    
}

void MyWidget::KeyCallback(int key, int scancode, int action, int mode)
{
    // call parent
    Widget::KeyCallback(key, scancode, action, mode);

    if(key == 256 && action == 1)
    {
        GetOpenGLWindow()->SetStatus(OpenGLWindow::EStatus::EShouldClose);

    }
}

int main() {
    OpenGLWindow window;
    
    MyWidget myWidget;
    myWidget.Show();
    
    return window.exec();
}
