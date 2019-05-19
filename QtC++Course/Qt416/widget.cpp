#include "widget.h"
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(400, 400);
    setupUi();
}

Widget::~Widget()
{

}

QSize Widget::sizeHint() const
{
    return QSize(1024, 768);
}

void Widget::setupUi()
{
    QLabel* label = new QLabel("Label", this);
    QFont font("Times", 12);
    label->setFont(font);
    label->move(100, 25);

    QTextEdit* textEdit = new QTextEdit(this);
    textEdit->move(70, 55);

    // text changed signal
    connect(textEdit, &QTextEdit::textChanged, [=](){
        qDebug() << "Text changed";
    });


    //copy, cut and paste
    QPushButton* copyButton = new QPushButton("Copy", this);
    copyButton->setMinimumSize(50, 25);
    copyButton->move(60, 250);
    connect(copyButton, &QPushButton::clicked, [=](){
        textEdit->copy();
    });

    QPushButton* cutButton = new QPushButton("Cut", this);
    cutButton->setMinimumSize(50, 25);
    cutButton->move(160, 250);
    connect(cutButton, &QPushButton::clicked, [=](){
        textEdit->cut();
    });

    QPushButton* pasteButton = new QPushButton("Paste", this);
    pasteButton->setMinimumSize(50, 25);
    pasteButton->move(260, 250);
    connect(pasteButton, &QPushButton::clicked, [=](){
        textEdit->paste();
    });

    //undo, redo
    QPushButton* undoButton = new QPushButton("Undo", this);
    undoButton->setMinimumSize(50, 25);
    undoButton->move(60, 300);
    connect(undoButton, &QPushButton::clicked, [=](){
        textEdit->undo();
    });

    QPushButton* redoButton = new QPushButton("Redo", this);
    redoButton->setMinimumSize(50, 25);
    redoButton->move(160, 300);
    connect(redoButton, &QPushButton::clicked, [=](){
        textEdit->redo();
    });

    //set text and html to the text edit
    QPushButton* plainTextButton = new QPushButton("Plain text", this);
    plainTextButton->setMinimumSize(50, 25);
    plainTextButton->move(60, 350);
    connect(plainTextButton, &QPushButton::clicked, [=](){
        textEdit->setPlainText("Nem tudom a videoba mit masolt bele");
    });

    QPushButton* htmlTextButton = new QPushButton("HTML text", this);
    htmlTextButton->setMinimumSize(50, 25);
    htmlTextButton->move(160, 350);
    connect(htmlTextButton, &QPushButton::clicked, [=](){
        textEdit->setHtml("<h1>ujfent</h1>");
    });

    //Grab text and html
    QPushButton* grabTextButton = new QPushButton("Grab text", this);
    grabTextButton->setMinimumSize(50, 25);
    grabTextButton->move(60, 400);
    connect(grabTextButton, &QPushButton::clicked, [=](){
        qDebug() << textEdit->toPlainText();
    });

    QPushButton* grabHtmlButton = new QPushButton("Grab html", this);
    grabHtmlButton->setMinimumSize(50, 25);
    grabHtmlButton->move(160, 400);
    connect(grabHtmlButton, &QPushButton::clicked, [=](){
        qDebug() << textEdit->toHtml();
    });
}
