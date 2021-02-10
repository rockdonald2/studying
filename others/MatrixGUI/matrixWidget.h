#ifndef MATRIXWIDGET_H
#define MATRIXWIDGET_H

#include <QWidget>
#include <QVector>

#include <matrixInterface.h>

using namespace standardMatrix;

namespace Ui {
class matrixWidget;
}

class matrixWidget : public QWidget
{
    Q_OBJECT

public:
    explicit matrixWidget(QWidget *parent = nullptr);
    ~matrixWidget();

private slots:
    void on_addButton_clicked();

    void on_subtButton_clicked();

    void on_multButton_clicked();

    void on_plusButton_clicked();

    void on_minusButton_clicked();

    void on_numMultButton_clicked();

private:
    Ui::matrixWidget *ui;
    Matrix A;
    Matrix B;
    Matrix C;

    bool is2by2 = false;
    bool is3by3 = true;
    void reset2by2();
    void reset3by3();

    bool extremistSlotEmpty();
    void checkExtremistSlot();
    bool AMatrix2by2IsModified();
    bool BMatrix2by2IsModified();
    bool AMatrix3by3IsModified();
    bool BMatrix3by3IsModified();
    bool anyExtremistSlotModified();

    void getData();
    void setData();
};

#endif // MATRIXWIDGET_H
