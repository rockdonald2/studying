#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QList>
#include <QColor>
#include <QPushButton>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_loadColorsButton_clicked();

    void on_saveColorButton_clicked();

private:
    Ui::Widget *ui;

    QList<QColor> colorList;

    void saveColor(QString key, QColor color);
    QColor loadColor(QString key);

    void setLoadedColor(QString key, int index, QPushButton* button);
};

#endif // WIDGET_H
