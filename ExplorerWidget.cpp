/* 
 * File:   ExplorerWidget.cpp
 * Author: jonas
 * 
 * Created on 28 novembre 2009, 16:58
 */

#include "ExplorerWidget.h"

ExplorerWidget::ExplorerWidget(QWidget *parent, Qt::WindowFlags f) : QWidget(parent, f) {
    this->setMinimumSize(150, 200);
    this->setMaximumSize(150, 200);

    this->layout = new QGridLayout(this);

    this->qtvExplorer = new QTreeView();

    this->layout->addWidget(this->qtvExplorer, 0, 0);

    this->layout->setAlignment(this->qtvExplorer, Qt::AlignCenter);

//    this->qtvExplorer->



}

ExplorerWidget::ExplorerWidget(const ExplorerWidget& orig) {
}

ExplorerWidget::~ExplorerWidget() {
}

