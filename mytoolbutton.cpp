#include "mytoolbutton.h"
#include <QPainter>
#include <QBrush>
#include <QLinearGradient>

MyToolButton::MyToolButton(QWidget *parent)
    : QToolButton(parent), m_ledColor(QColor(Qt::red)), m_label("label"), m_label2("label2"), iDir(1), m_Width(LED_WIDTH)
{
}

MyToolButton::~MyToolButton()
{

}

void MyToolButton::paintEvent(QPaintEvent * e)
{
    Q_UNUSED(e)

    QFont l_qFont;
    QFontMetrics l_qFontMetrics(l_qFont);
    int textLength=l_qFontMetrics.width(" "+m_label+" ");
    int textLength2=l_qFontMetrics.width(" "+m_label2+" ");

    if(m_Width>=24)
    {
        textLength = textLength2>textLength?textLength2:textLength;
    }
    setFixedWidth(textLength+m_Width);
    setFixedHeight(m_Width);
    drawLed(textLength);
}

void MyToolButton::randColor()
{
    int h,s,v;
    m_ledColor.getHsv(&h,&s,&v);
    if(iDir == 1)
    {
        v++;
        if(v>=255)
        {
            v = 255;
            iDir = 0;
        }
    }
    else if(iDir == 0)
    {
        v--;
        if(v<=100)
        {
            v=100;
            iDir =1;
        }
    }
    m_ledColor.setHsv(h,s,v);
}

void MyToolButton::drawLed(int p_length)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);

    randColor();
    qreal l_margin = 4;
    qreal l_height = height()-l_margin;
    QRadialGradient gradient(1+l_height/2, l_height/2+l_margin/2, m_Width*3/5);

    gradient.setColorAt(0.0, m_ledColor);
    gradient.setColorAt(0.2, m_ledColor);
    gradient.setColorAt(1.0, Qt::black);
    painter.setBrush(gradient);
    painter.setPen( Qt::NoPen );
    painter.drawEllipse(1,static_cast<int>(l_margin/2),static_cast<int>(l_height),static_cast<int>(l_height));

    qreal l_highlight = m_Width*2/5;
    QRadialGradient radGrad(1+l_height/2,l_height/2+l_margin/2-m_Width/4, m_Width/4);

    radGrad.setColorAt(0.0, Qt::white);
    radGrad.setColorAt(1.0, m_ledColor);
    painter.setBrush(radGrad);
    painter.setPen(Qt::NoPen);
    painter.drawEllipse(static_cast<int>(1+l_height/2-l_highlight/2),static_cast<int>(l_height/2-l_highlight/2+l_margin/2-m_Width/8),static_cast<int>(l_highlight),static_cast<int>(l_highlight-m_Width/8));


    if(m_Width < 24)
    {
        painter.setPen(m_ledColor);
        QRect rect(m_Width,0,p_length,height());
        painter.drawText(rect,Qt::AlignLeft | Qt::AlignVCenter," "+m_label+" ");
    }
    else
    {
        painter.setPen(m_ledColor);
        QRect rect(m_Width,0,p_length,height()/2);
        painter.drawText(rect,Qt::AlignLeft | Qt::AlignVCenter," "+m_label+" ");

        QRect rect2(m_Width,height()/2,p_length,height()/2);
        painter.drawText(rect2,Qt::AlignLeft | Qt::AlignVCenter," "+m_label2+" ");
    }
}


