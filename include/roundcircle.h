﻿#ifndef ROUNDCIRCLE_H
#define ROUNDCIRCLE_H

/**
 * 旋转圆控件 作者:feiyangqingyun(QQ:517216493) 2016-10-22
 * 1. 可设置步长。
 * 2. 可设置各种颜色。
 * 3. 可设置顺时针逆时针旋转。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT RoundCircle : public QWidget
#else
class RoundCircle : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(int step READ getStep WRITE setStep)
    Q_PROPERTY(bool clockWise READ getClockWise WRITE setClockWise)

    Q_PROPERTY(QColor bgColorStart READ getBgColorStart WRITE setBgColorStart)
    Q_PROPERTY(QColor bgColorEnd READ getBgColorEnd WRITE setBgColorEnd)

    Q_PROPERTY(QColor pieColor1Start READ getPieColor1Start WRITE setPieColor1Start)
    Q_PROPERTY(QColor pieColor1End READ getPieColor1End WRITE setPieColor1End)
    Q_PROPERTY(QColor pieColor2Start READ getPieColor2Start WRITE setPieColor2Start)
    Q_PROPERTY(QColor pieColor2End READ getPieColor2End WRITE setPieColor2End)

public:
    explicit RoundCircle(QWidget *parent = 0);
    ~RoundCircle();

protected:
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawPie(QPainter *painter);

private:
    int step;               //每次旋转的步长
    bool clockWise;         //顺时针

    QColor bgColorStart;    //背景渐变开始颜色
    QColor bgColorEnd;      //背景渐变结束颜色

    QColor pieColor1Start;  //圆形渐变色1开始颜色
    QColor pieColor1End;    //圆形渐变色1结束颜色
    QColor pieColor2Start;  //圆形渐变色2开始颜色
    QColor pieColor2End;    //圆形渐变色2结束颜色

    double angle;           //角度值
    double radius;          //半径
    QTimer *timer;          //定时器更新

private slots:
    void updateAngle();     //更新角度

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //获取和设置旋转的步长
    int getStep() const;
    void setStep(int step);

    //获取和设置进度旋转方向
    bool getClockWise() const;
    void setClockWise(bool clockWise);

    //获取和设置背景渐变色
    QColor getBgColorStart() const;
    void setBgColorStart(const QColor &bgColorStart);

    QColor getBgColorEnd() const;
    void setBgColorEnd(const QColor &bgColorEnd);

    //获取和设备饼状圆形交替渐变色
    QColor getPieColor1Start() const;
    void setPieColor1Start(const QColor &pieColor1Start);

    QColor getPieColor1End() const;
    void setPieColor1End(const QColor &pieColor1End);

    QColor getPieColor2Start() const;
    void setPieColor2Start(const QColor &pieColor2Start);

    QColor getPieColor2End() const;
    void setPieColor2End(const QColor &pieColor2End);
};

#endif // ROUNDCIRCLE_H
