﻿#ifndef PROGRESSSHADOW_H
#define PROGRESSSHADOW_H

/**
 * 光晕进度条控件 作者:feiyangqingyun(QQ:517216493) 2019-10-06
 * 1. 可设置最大值、最小值、范围值、当前值。
 * 2. 可设置精确度，小数点后几位。
 * 3. 可设置最小值起始角度。
 * 4. 可设置是否百分比显示值。
 * 5. 可设置光晕阴影颜色。
 * 6. 可设置进度颜色。
 * 7. 可设置进度背景颜色。
 * 8. 可设置文字颜色。
 * 9. 采用动画机制产生进度效果。
 */

#include <QWidget>

#ifdef quc
class Q_DECL_EXPORT ProgressShadow : public QWidget
#else
class ProgressShadow : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(double minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(double maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(double value READ getValue WRITE setValue)

    Q_PROPERTY(int precision READ getPrecision WRITE setPrecision)
    Q_PROPERTY(int nullPosition READ getNullPosition WRITE setNullPosition)
    Q_PROPERTY(bool percent READ getPercent WRITE setPercent)

    Q_PROPERTY(QColor shadowColor READ getShadowColor WRITE setShadowColor)
    Q_PROPERTY(QColor progressColor READ getProgressColor WRITE setProgressColor)
    Q_PROPERTY(QColor bgColor READ getBgColor WRITE setBgColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)

public:
    explicit ProgressShadow(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void drawBg(QPainter *painter);
    void drawProgress(QPainter *painter);
    void drawText(QPainter *painter);

private:
    double minValue;        //最小值
    double maxValue;        //最大值
    double value;           //目标值

    int precision;          //精确度
    int nullPosition;       //起始角度
    bool percent;           //百分比显示

    QColor shadowColor;     //光晕颜色
    QColor progressColor;   //进度颜色
    QColor bgColor;         //背景颜色
    QColor textColor;       //文字颜色

public:
    //默认尺寸和最小尺寸
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    //设置范围值
    void setRange(double minValue, double maxValue);
    void setRange(int minValue, int maxValue);

    //获取和设置最小值
    double getMinValue() const;
    void setMinValue(double minValue);

    //获取和设置最大值
    double getMaxValue() const;
    void setMaxValue(double maxValue);

    //获取和设置目标值
    double getValue() const;
    void setValue(double value);

    //获取和设置精确度
    int getPrecision() const;
    void setPrecision(int precision);

    //获取和设置最小值位置
    int getNullPosition() const;
    void setNullPosition(int nullPosition);

    //获取和设置百分比显示
    bool getPercent() const;
    void setPercent(bool percent);

    //获取和设置光晕颜色
    QColor getShadowColor() const;
    void setShadowColor(const QColor &shadowColor);

    //获取和设置进度颜色
    QColor getProgressColor() const;
    void setProgressColor(const QColor &progressColor);

    //获取和设置背景颜色
    QColor getBgColor() const;
    void setBgColor(const QColor &bgColor);

    //获取和设置文字颜色
    QColor getTextColor() const;
    void setTextColor(const QColor &textColor);

public Q_SLOTS:
    void setValue(int value);

Q_SIGNALS:
    void valueChanged(double value);
};

#endif // PROGRESSSHADOW_H
