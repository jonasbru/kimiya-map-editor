/* 
 * File:   ItemsWidget.cpp
 * Author: arnaudboeglin
 * 
 * Created on August 3, 2009, 9:42 PM
 */

#include "ItemsWidget.h"

#include <iostream>

#include <QtCore/QDir>

ItemsWidget::ItemsWidget(QWidget *parent, Qt::WindowFlags f) : QWidget(parent, f) {
    this->setMinimumSize(150, 200);
    this->setMaximumSize(150, 200);

    this->layout = new QGridLayout(this);


    this->qcbItemThemes = new QComboBox(this);
    this->qcbItems = new QComboBox(this);
    this->preview = new PreviewItemWidget(this);

    this->layout->addWidget(this->qcbItemThemes, 0, 0);
    this->layout->addWidget(this->qcbItems, 1, 0);
    this->layout->addWidget(this->preview, 2, 0);

    this->setLayout(this->layout);

    this->layout->setAlignment(this->preview, Qt::AlignCenter);

    QObject::connect(this->qcbItemThemes, SIGNAL(currentIndexChanged(int)), this, SLOT(itemThemeHasChanged(int)));
    QObject::connect(this->qcbItems, SIGNAL(currentIndexChanged(int)), this, SLOT(itemHasChanged(int)));

    this->loadItems();
}

ItemsWidget::ItemsWidget(const ItemsWidget& orig) {
}

ItemsWidget::~ItemsWidget() {
    for(int i=0; i<this->items.count(); i++){
        for(int j=0; j<this->items.values().at(i).count(); j++){
            delete this->items.values().at(i).at(j).second;
        }
    }
}

void ItemsWidget::loadItems(){
    QDir dir(RESSOURCES_PATH);
    const QStringList &dirList = dir.entryList(QDir::Dirs);

    //Load images :
    for(int i=0; i<dirList.count(); i++){
        if(dirList.at(i) != "." && dirList.at(i) != ".."){
            QDir theme(dir.absolutePath()+QDir::separator()+dirList.at(i));
            QList<QPair<QString, QImage*> > list;
            this->items.insert(dirList.at(i), list);

            const QStringList &imgList = theme.entryList(QDir::Files | QDir::Readable);

            for(int j=0; j<imgList.count(); j++){
                QImage *img = new QImage(theme.absolutePath()+QDir::separator()+imgList.at(j));
                QPair<QString, QImage*> p(imgList.at(j), img);
                this->items[dirList.at(i)].append(p);
            }
        }
    }

    //Initialise the QComboBoxs :
    this->qcbItemThemes->addItem("all");

    for(int i=0; i<this->items.count(); i++){
        this->qcbItemThemes->addItem(this->items.keys().at(i));

//        for(int j=0; j<this->items.values().at(i).count(); j++){
//            QVariant v = QVariant::fromValue(this->items.values().at(i).at(j).second);
//            this->qcbItems->addItem(this->items.values().at(i).at(j).first, v);
//        }
    }
}

void ItemsWidget::itemThemeHasChanged(int newIndex){
    this->qcbItems->clear();

    if(this->qcbItemThemes->itemText(newIndex) == "all"){
        for(int i=0; i<this->items.count(); i++){
            for(int j=0; j<this->items.values().at(i).count(); j++){
                QVariant v = QVariant::fromValue(this->items.values().at(i).at(j).second);
                this->qcbItems->addItem(this->items.values().at(i).at(j).first, v);
            }
        }
    }
    else{
        QList<QPair<QString, QImage*> > &list = this->items[this->qcbItemThemes->itemText(newIndex)];
        for(int i=0; i<list.count(); i++){
            QVariant v = QVariant::fromValue(list.at(i).second);
            this->qcbItems->addItem(list.at(i).first, v);
        }
    }
}

void ItemsWidget::itemHasChanged(int newIndex){
    QImage *qi = this->qcbItems->itemData(newIndex).value<QImage*>();
    
    this->preview->setImage(qi);

    this->preview->repaint();
}
