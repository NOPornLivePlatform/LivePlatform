#pragma once


#ifndef QIPADDRESS_H
#define QIPADDRESS_H

/**
 * IP��ַ�����ؼ� ����:feiyangqingyun(QQ:517216493) 2017-8-11
 * 1:������IP��ַ,�Զ������
 * 2:�����IP��ַ
 * 3:֧�ְ���СԲ���Զ��л�
 * 4:֧���˸���Զ��л�
 * 5:֧��IP��ַ����
 * 6:�����ñ���ɫ/�߿���ɫ/�߿�Բ�ǽǶ�
 */

#include <QLineEdit>
#include <QLabel>

class QIPAddress : public QWidget
{
    Q_OBJECT
	Q_PROPERTY(QString ip READ getIP WRITE setIP)
	Q_PROPERTY(QString bgColor READ getBgColor WRITE setBgColor)
	Q_PROPERTY(QString borderColor READ getBorderColor WRITE setBorderColor)
	Q_PROPERTY(int borderRadius READ getBorderRadius WRITE setBorderRadius)

public:
    explicit QIPAddress(QWidget* parent = 0);

protected:
    bool eventFilter(QObject* watched, QEvent* event);

private:
    QLabel* labDot1;    //��һ��СԲ��
    QLabel* labDot2;    //�ڶ���СԲ��
    QLabel* labDot3;    //������СԲ��

    QLineEdit* txtIP1;  //IP��ַ���������1
    QLineEdit* txtIP2;  //IP��ַ���������2
    QLineEdit* txtIP3;  //IP��ַ���������3
    QLineEdit* txtIP4;  //IP��ַ���������4

    QString ip;         //IP��ַ
    QString bgColor;    //������ɫ
    QString borderColor;//�߿���ɫ
    int borderRadius;   //�߿�Բ�ǽǶ�


    QFrame* frameIP;

private slots:
    void textChanged(const QString& text);

public:
    //��ȡIP��ַ
    QString getIP()                 const;

    QSize sizeHint()                const;
    QSize minimumSizeHint()         const;

public Q_SLOTS:
    //����IP��ַ
    void setIP(const QString& ip);
    //���
    void clear();

    //���ñ�����ɫ
    void setBgColor(const QString& bgColor);
    QString getBgColor()const;
    //���ñ߿���ɫ
    void setBorderColor(const QString& borderColor);
    QString getBorderColor()const;
    //���ñ߿�Բ�ǽǶ�
    void setBorderRadius(int borderRadius);
    int getBorderRadius()const;

    void applyStyleSheet();

};

#endif // QIPADDRESS_H
