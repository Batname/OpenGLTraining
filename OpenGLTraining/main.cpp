#include <OpenGLWindow/OpenGLWindow.hpp>
#include <OpenGLWindow/Widget.hpp>
#include <stdio.h>

class MyWidget : public Widget
{
public:
protected:
    virtual void Render() override;
private:
};

void MyWidget::Render()
{
    // call parent
    Widget::Render();
    
    printf("child MyWidget Render\n");
}

int main() {
    OpenGLWindow window;
    
    MyWidget myWidget;
    myWidget.Show();
    
    return window.exec();
}
