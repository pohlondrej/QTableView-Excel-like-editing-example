#include "exampledialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExampleDialog w;
    w.show();

    return a.exec();
}
