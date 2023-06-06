#include "arcwidget.h"

ArcWidget::ArcWidget(QWidget *parent)
    : QWidget(parent), m_nPeopleCount(0)
{
    this->resize(600, 600);

    m_answerMap.insert("A", 3);
    m_answerMap.insert("B", 5);
    m_answerMap.insert("C", 8);
    m_answerMap.insert("D", 2);

    m_answerStrList = m_answerMap.keys();
    m_numList = m_answerMap.values();
    foreach (int num, m_numList) {
        m_nPeopleCount += num;
    }
}

ArcWidget::~ArcWidget()
{

}

void ArcWidget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::NoBrush);
//    painter.drawImage(this->rect(),m_bg);

    QRectF rect(-120, -120,
                (120 << 1), (120 << 1));
    QList<QColor> colorList;

    painter.translate(220, 255);
    qreal startAngle = 0;
    foreach (int num, m_numList) {

        // Генерация случайных цветов и фильтрация белого
        int colorR, colorG, colorB;
        while(1)
        {
            colorR = rand()%256;
            colorG = rand()%256;
            colorB = rand()%256;

            if(colorR == 255 && colorG == 255 && colorB == 255)
            {
                continue;
            }
            else
            {
                break;
            }
        }
        QColor color(colorR, colorG, colorB);
        colorList.append(color);

        painter.setPen(Qt::NoPen);
        painter.setBrush(QBrush(color));

                 // Доля вариантов ответа
        qreal percentNum = (qreal)num/(qreal)m_nPeopleCount;
                 // Угол, соответствующий пропорции
        qreal arcLength = 360*percentNum;

                 // Рисуем веер
        QPainterPath path;
        path.arcTo(rect, startAngle, arcLength);

                 // Угол биссектрисы веера
        qreal middleAngle = startAngle + arcLength/2;
        qreal radianNum = 0;
        if(middleAngle >= 0 && middleAngle < 90)
        {
            radianNum = middleAngle*m_pi/180;
        }
        else if(middleAngle >= 90 && middleAngle < 180)
        {
            radianNum = (180 - middleAngle)*m_pi/180;
        }
        else if(middleAngle >= 180 && middleAngle < 270)
        {
            radianNum = (middleAngle - 180)*m_pi/180;
        }
        else if(middleAngle >= 270 && middleAngle < 360)
        {
            radianNum = (360 - middleAngle)*m_pi/180;
        }
                 // Расстояние между серединой биссектрисы и началом координат
        qreal textPosY = 60*sin(radianNum);
        qreal textPosX = 60*cos(radianNum);
                 // Определяем координаты средней точки биссектрисы согласно квадранту, где расположена биссектриса
        if(middleAngle >= 0 && middleAngle < 90)
        {
            textPosY = -textPosY;
        }
        else if(middleAngle >= 90 && middleAngle < 180)
        {
            textPosX = -textPosX;
            textPosY = -textPosY;
        }
        else if(middleAngle >= 180 && middleAngle < 270)
        {
            textPosX = -textPosX;
        }
        startAngle += arcLength;
        QString percentStr = QString::number(percentNum*100 + 0.5);
        percentStr = getPercentInt(percentStr) + "%";
        painter.drawPath(path);
        painter.setPen(QColor(Qt::white));
        painter.drawText(textPosX - 25, textPosY -10,
                         50, 20, Qt::AlignCenter, percentStr);
    }
    painter.setBrush(Qt::NoBrush);
    painter.setPen(QColor(0, 0, 0));
    painter.translate(-220, -255);
         // Рисуем столбец метки справа
    QFont ft;
    ft.setPixelSize(15);
    painter.setFont(ft);
    int textStart = 140;
    foreach (QString answerStr, m_answerStrList) {
        painter.drawText(350, textStart,
                         40, 16,
                         Qt::AlignRight, answerStr);
        textStart += 30;
    }
    textStart = 143;
    painter.setPen(Qt::NoPen);
    foreach (QColor color, colorList) {
        painter.setBrush(QBrush(color));
        painter.drawRect(402, textStart, 15, 15);
        textStart += 30;
    }
    QWidget::paintEvent(e);
}
QString ArcWidget::getPercentInt(const QString &percentStr)
{
    QString percentIntStr;
    for(int i = 0;i < percentStr.size();++i)
    {
        if(percentStr.at(i) == '.')
        {
            break;
        }
        percentIntStr += percentStr.at(i);
    }
    return percentIntStr;
}
