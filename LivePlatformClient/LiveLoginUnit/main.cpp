#include "LiveLoginUnit.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // �������ú��û��б�
    thatboy::utils::loadConfig();
    thatboy::utils::loadUsers();

    LiveLoginUnit w;
    w.show();
    return a.exec();
}
