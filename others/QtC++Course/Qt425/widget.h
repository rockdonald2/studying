#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

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
    void on_addButton_clicked();

    void on_deleteButton_clicked();

    void on_selectedButton_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
