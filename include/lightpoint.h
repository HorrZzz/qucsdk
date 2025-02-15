﻿#ifndef LIGHTPOINT_H
#define LIGHTPOINT_H

/**
 * 呼吸点控件 作者:feiyangqingyun(QQ:517216493) 2017-11-27
 * 1. 可设置呼吸间隔。
 * 2. 可设置颜色透明渐变步长。
 * 3. 可设置背景颜色。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT LightPoint : public QWidget
#else
class LightPoint : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(int step READ getStep WRITE setStep)
    Q_PROPERTY(int interval READ getInterval WRITE setInterval)
    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)

public:
    explicit LightPoint(QWidget *parent = 0);
    ~LightPoint();

protected:
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);

private:
    int step;           //颜色透明渐变步长
    int interval;       //定时器间隔
    QColor bgColor;     //背景颜色

    QTimer *timer;      //绘制定时器
    int offset;         //偏移量
    bool add;           //是否增加

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置颜色透明渐变步长
    int getStep() const;
    void setStep(int step);

    //获取和设置定时器间隔
    int getInterval() const;
    void setInterval(int interval);

    //获取和设置背景颜色
    QColor getBgColor() const;
    void setBgColor(const QColor &bgColor);
};

#endif // LIGHTPOINT_H
