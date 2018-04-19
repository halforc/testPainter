#include "dialog.h"
#include "ui_dialog.h"

#include <QPaintEvent>
#include <QPainter>
#include <QWheelEvent>
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    value(1.0)
{
    ui->setupUi(this);

    this->resize(800,800);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    QPixmap pix;
    pix.load("d://test.jpg");
    //painter.drawPixmap(0,0,600,600,pix);

    qreal width = pix.width(); //获得以前图片的宽和高
    qreal height = pix.height();

    pix = pix.scaled(width*value,height*value,Qt::KeepAspectRatio);
    //将图片的宽和高都扩大两倍，并且在给定的矩形内保持宽高的比值
    painter.drawPixmap(100,100,pix);
    qDebug()<<"paint "<< value;
}

void Dialog::wheelEvent(QWheelEvent *e){
    if(e->delta() > 0){
        value = value * 1.1;
            qDebug()<<"zoom";

    }else{
        value = value * 0.9;
            qDebug()<<"111";
    }
    repaint();
}

