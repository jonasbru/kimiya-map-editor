/* 
 * File:   PreviewItemWidget.cpp
 * Author: arnaudboeglin
 * 
 * Created on August 4, 2009, 4:29 PM
 */

#include "PreviewItemWidget.h"

#include <iostream>
#include <QtGui/QPainter>
#include <QtCore/QRect>

PreviewItemWidget::PreviewItemWidget(QWidget *parent, Qt::WindowFlags f) : QWidget(parent, f) {
    this->setMinimumSize(100, 100);
    this->setMaximumSize(100, 100);
    this->toDisplay = NULL;
}

PreviewItemWidget::PreviewItemWidget(const PreviewItemWidget& orig) {
}

PreviewItemWidget::~PreviewItemWidget() {
}

void PreviewItemWidget::setImage(QImage *image){
    this->toDisplay = image;
}

void PreviewItemWidget::paintEvent(QPaintEvent *event){
    if(this->toDisplay){
        //DISPLAY IMAGE:

        QPainter p(this);
        int w = this->toDisplay->width();
        int h = this->toDisplay->height();
        int dispW = 0;
        int dispH = 0;
        
        float ratio = w > h ? w / this->width() : h / this->height();

        dispW = w / ratio;
        dispH = h / ratio;

        const QRect &src = this->toDisplay->rect();
        QRect dest(((this->width() - dispW) / 2), ((this->height() - dispH) / 2), dispW, dispH);
        

        p.drawImage(dest, *this->toDisplay, src);
    }
}
