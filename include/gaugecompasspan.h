﻿#ifndef GAUGECOMPASSPAN_H
#define GAUGECOMPASSPAN_H

/**
 * 指南针面板控件 作者:东门吹雪(QQ:709102202) 整理:飞扬青云(QQ:517216493) 2019-04-23
 * 1. 可设置当前度数以及精确度。
 * 2. 可设置背景颜色、文字颜色。
 * 3. 可设置边框颜色、边框宽度。
 * 4. 可设置正北点颜色。
 * 5. 可设置其他方向点颜色。
 * 6. 可设置指针颜色。
 * 7. 自动计算方位变显示。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT GaugeCompassPan : public QWidget
#else
class GaugeCompassPan : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(double value READ getValue WRITE setValue)
    Q_PROPERTY(int precision READ getPrecision WRITE setPrecision)

    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)
    Q_PROPERTY(QColor borderColor READ getBorderColor WRITE setBorderColor)
    Q_PROPERTY(int borderWidth READ getBorderWidth WRITE setBorderWidth)

    Q_PROPERTY(QColor northDotColor READ getNorthDotColor WRITE setNorthDotColor)
    Q_PROPERTY(QColor otherDotColor READ getOtherDotColor WRITE setOtherDotColor)
    Q_PROPERTY(QColor pointerColor READ getPointerColor WRITE setPointerColor)

public:
    explicit GaugeCompassPan(QWidget *parent = 0);
    ~GaugeCompassPan();

protected:
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawFourDots(QPainter *painter);
    void drawFourText(QPainter *painter);
    void drawPointer(QPainter *painter);
    void drawValue(QPainter *painter);

private:
    double value;           //当前值
    int precision;          //精确度(小数点后几位)

    QColor bgColor;         //背景颜色
    QColor textColor;       //文字颜色
    QColor borderColor;     //边框颜色
    int borderWidth;        //边框宽度

    QColor northDotColor;   //正北点颜色
    QColor otherDotColor;   //其它方向点颜色
    QColor pointerColor;    //指针颜色

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置当前值
    double getValue() const;
    void setValue(double value);

    //获取和设置精确度
    int getPrecision() const;
    void setPrecision(int precision);

    //获取和设置背景色
    QColor getBgColor() const;
    void setBgColor(const QColor &bgColor);

    //获取和设置文字颜色
    QColor getTextColor() const;
    void setTextColor(const QColor &textColor);

    //获取和设置外边框颜色
    QColor getBorderColor() const;
    void setBorderColor(const QColor &borderColor);

    //获取和设置外边框宽度
    int getBorderWidth() const;
    void setBorderWidth(int borderWidth);

    //获取和设置正北点颜色
    QColor getNorthDotColor() const;
    void setNorthDotColor(const QColor &northDotColor);

    //获取和设置其它方向点颜色
    QColor getOtherDotColor() const;
    void setOtherDotColor(const QColor &otherDotColor);

    //获取和设置指针颜色
    QColor getPointerColor() const;
    void setPointerColor(const QColor &pointerColor);

public Q_SLOTS:
    //设置当前值
    void setValue(int value);

Q_SIGNALS:
    //值变化信号
    void valueChanged(double value);
};

#endif // GAUGECOMPASSPAN_H
