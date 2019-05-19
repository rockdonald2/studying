#include "widget.h"
#include "ui_widget.h"

#include <QNetworkReply>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    netManager = new QNetworkAccessManager(this);
    netReply = nullptr;
    mDataBuffer = new QByteArray();

    //define net requests
    QNetworkRequest request;
    request.setUrl(QUrl("https://www.qt.io"));

    netReply = netManager->get(request);
    connect (netReply, &QIODevice::readyRead, this, &Widget::dataReadyToRead);
    connect (netReply, &QNetworkReply::finished, this, &Widget::dataReadFinished);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::dataReadyToRead()
{
    qDebug() << "Some data is available";
    mDataBuffer->append(netReply->readAll());
}

void Widget::dataReadFinished()
{
    if (netReply->error())
    {
        qDebug() << "Error: " << netReply->errorString();
    }

    else {
        ui->textEdit->setPlainText(QString(*mDataBuffer));
    }
}
