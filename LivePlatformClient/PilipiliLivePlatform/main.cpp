#pragma execution_character_set("utf-8")
#include "LivePlatform.h"
#include "LiveLoginDialog.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // �������ú��û��б�
    thatboy::utils::loadConfig();
    thatboy::utils::loadUserData();

    LiveLoginDialog d;
    d.exec();
    QMessageBox::information(nullptr, "Tip","���滹û��");
    LivePlatform w;
    w.show();
    return a.exec();
}
