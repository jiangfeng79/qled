#ifndef MYTOOLBUTTON_H
#define MYTOOLBUTTON_H

#include <QObject>
#include <QToolButton>
#include <QTimer>
#include <QTime>
#define LED_WIDTH 32

class MyToolButton : public QToolButton
{
public:
    MyToolButton(QWidget *parent=NULL);
    ~MyToolButton();

    inline void setLedColor(QColor c) { m_ledColor = c; }
    inline void setText(QString s) { m_label = s; }
    inline void setText2(QString s) { m_label2 = s; }
    inline void setLedWidth(int w) { m_Width = w; }
protected:
    void paintEvent(QPaintEvent *event);

private:
    void randColor();
    void drawLed(int length);
    QColor m_ledColor;
    QString m_label, m_label2;
    int iDir, m_Width;
};


#endif // MYTOOLBUTTON_H
