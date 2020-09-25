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

#ifndef _DEBUG
    try
    {
#endif
        LiveLoginDialog d;
        if (d.exec() == QDialog::Accepted)
        {
            LivePlatform w;
            w.show();

            thatboy::utils::saveUserData();
            thatboy::utils::saveConfig();
            return a.exec();
        }
        else
        {
            thatboy::utils::saveUserData();
            thatboy::utils::saveConfig();
            return 0;
        }
#ifndef _DEBUG
    }
    catch (...)
    {
        try {
            thatboy::utils::saveUserData();
            thatboy::utils::saveConfig();
        }
        catch (...)
        {
            QMessageBox::warning(nullptr, "����", "���������Թ��ϣ������޷�����.");
            return -2;
        }
        QMessageBox::warning(nullptr, "����", "���������Թ��ϣ������ѱ���.");
        return -1;
    }
#endif
}
