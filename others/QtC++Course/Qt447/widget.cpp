#include "widget.h"
#include "ui_widget.h"

#include <QNetworkRequest>
#include <QDebug>

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QVariantMap>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget), mNetManager(new QNetworkAccessManager), mNetReply(nullptr),
        mDataBuffer(new QByteArray)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_fetchButton_clicked()
{
    //initialize our API data
    const QUrl API_ENDPOINT("https://jsonplaceholder.typicode.com/posts");

    QNetworkRequest request;
    request.setUrl(API_ENDPOINT);

    mNetReply = mNetManager->get(request);

    connect (mNetReply, &QIODevice::readyRead, this, &Widget::dataReadyToRead);
    connect (mNetReply, &QNetworkReply::finished, this, &Widget::dataReadFinished);
}

void Widget::dataReadyToRead()
{
    mDataBuffer->append(mNetReply->readAll());
}

void Widget::dataReadFinished()
{
    if (mNetReply->error())
    {
        qDebug() << "Error: " << mNetReply->errorString();
    }
    else {
        //qDebug() << "Data from the server: " << QString(*mDataBuffer);

        //turn the data into a json document
        QJsonDocument doc = QJsonDocument::fromJson(*mDataBuffer);

        //turn the data into a json array to iterate through
        QJsonArray array = doc.array();

        //if you get the data from the json document as an object
        /* QJsonDocument objectDoc = QJsonDocument::fromJson(*mDataBuffer);
         * QJsonObject ob = objectDoc.toVariant().toJsonObject();*/

        for (int i = 0; i < array.size(); ++i)
        {
            QJsonObject object = array.at(i).toObject();

            QVariantMap map = object.toVariantMap();

            QString title = map["title"].toString();

            ui->listWidget->addItem("[" + QString::number(i+1) + "]" + title);
        }
    }
}
