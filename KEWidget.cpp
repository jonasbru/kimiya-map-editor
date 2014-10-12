/* 
 * File:   KEWidget.cpp
 * Author: arnaudboeglin
 * 
 * Created on July 31, 2009, 12:38 PM
 */

#include "KEWidget.h"

#include <Director.h>
//#include <GL/gl.h>
//#include <iostream>

KEWidget::KEWidget(QWidget *parent, const QGLWidget *shareWidget, Qt::WindowFlags f) : QGLWidget(parent, shareWidget, f) {
    QGLFormat fmt;
    fmt.setOverlay(true);
    fmt.setDoubleBuffer(true);
    this->setFormat(fmt);
}

KEWidget::KEWidget(QGLContext *context, QWidget *parent, const QGLWidget *shareWidget, Qt::WindowFlags f) : QGLWidget(context, parent, shareWidget, f){
    QGLFormat fmt;
    fmt.setOverlay(true);
    fmt.setDoubleBuffer(true);
    this->setFormat(fmt);
}

KEWidget::KEWidget(const QGLFormat &format, QWidget *parent, const QGLWidget *shareWidget, Qt::WindowFlags f) : QGLWidget(format, parent, shareWidget, f){
    
}

KEWidget::KEWidget(const KEWidget& orig){
}

KEWidget::~KEWidget() {
}

void KEWidget::initializeGL(){
    ke::Director::getDirector()->init();
}

void KEWidget::resizeGL(int width, int height){

}

void KEWidget::paintGL(){
    ke::Director::getDirector()->drawScene();
}

void KEWidget::keyPressEvent(QKeyEvent *e){
    
}

void KEWidget::timeOut(){
    
}