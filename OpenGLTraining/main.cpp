#include <OpenGLWindow/OpenGLWindow.hpp>
#include <OpenGLWindow/Widget.hpp>
#include <stdio.h>

class MyWidget : public Widget
{
public:
protected:
    virtual void Render() override;
    virtual void KeyCallback(int key, int scancode, int action, int mode) override;
private:
};

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
