#include <QApplication>
#include "MyForm.h"

int main (int argc, char **argv) {
    QApplication app(argc, argv);
    MyForm f;
    f.show();
    return app.exec();
}
