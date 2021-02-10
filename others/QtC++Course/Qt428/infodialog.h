#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QDialog>

namespace Ui {
class infoDialog;
}

class infoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit infoDialog(QWidget *parent = nullptr);
    ~infoDialog();

    QString getFavoriteOS() const;
    void setFavoriteOS(const QString &value);

    QString getPosition() const;
    void setPosition(const QString &value);

private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::infoDialog *ui;

    QString position;
    QString favoriteOS;
};

#endif // INFODIALOG_H
