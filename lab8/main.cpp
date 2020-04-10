#include "window.h"
#include "renderarea.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window w;
    RenderArea r;
    w.show();
    return a.exec();
}
