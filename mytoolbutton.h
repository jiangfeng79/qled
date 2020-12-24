#ifndef MYTOOLBUTTON_H
#define MYTOOLBUTTON_H

#include <QObject>
#include <QToolButton>
#include <QTimer>
#include <QTime>
#define LED_WIDTH 31

class MyToolButton : public QToolButton
{
public:
    MyToolButton(QWidget *parent=NULL);
    ~MyToolButton();

    inline void setLedColor(QColor c) { m_ledColor = c; }
    inline void setText(QString s) { m_label = s; }
    inline void setText2(QString s) { m_label2 = s; }
protected:
    void paintEvent(QPaintEvent *event);

private:
    void randColor();
    void drawLed(int length);
    QColor m_ledColor;
    QString m_label, m_label2;
    int iDir;
};


#endif // MYTOOLBUTTON_H
