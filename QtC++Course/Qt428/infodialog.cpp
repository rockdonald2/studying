#include "infodialog.h"
#include "ui_infodialog.h"

infoDialog::infoDialog(QWidget *parent) :
    QDialog(parent, Qt::WindowSystemMenuHint | Qt::WindowTitleHint),
    ui(new Ui::infoDialog)
{
    ui->setupUi(this);

    ui->positionLineEdit->setPlaceholderText("Position");
}

infoDialog::~infoDialog()
{
    delete ui;
}

void infoDialog::on_okButton_clicked()
{
    QString userPosition = ui->positionLineEdit->text();

    if(!userPosition.isEmpty())
    {
        position = userPosition;

        if(ui->windowsButton->isChecked())
        {
            favoriteOS = "windows";
        }

        if(ui->macButton->isChecked())
        {
            favoriteOS = "mac";
        }

        if(ui->linuxButton->isChecked())
        {
            favoriteOS = "linux";
        }
    }

    //accept the dialog, which means the dialog is accepted
    accept();
}

void infoDialog::on_cancelButton_clicked()
{
    //reject the dialog, which means the dialog is rejected
    reject();
}

QString infoDialog::getPosition() const
{
    return position;
}

void infoDialog::setPosition(const QString &value)
{
    position = value;
}

QString infoDialog::getFavoriteOS() const
{
    return favoriteOS;
}

void infoDialog::setFavoriteOS(const QString &value)
{
    favoriteOS = value;
}
