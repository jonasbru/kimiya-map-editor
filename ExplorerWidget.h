/* 
 * File:   ExplorerWidget.h
 * Author: jonas
 *
 * Created on 28 novembre 2009, 16:58
 */

#ifndef _EXPLORERWIDGET_H
#define	_EXPLORERWIDGET_H

#include <QtGui/QWidget>
#include <QtGui/QTreeView>
#include <QtGui/QGridLayout>

class ExplorerWidget : public QWidget {

    Q_OBJECT

public:

    ExplorerWidget(QWidget *parent = 0, Qt::WindowFlags f = 0);
    ExplorerWidget(const ExplorerWidget& orig);
    virtual ~ExplorerWidget();

private:

    QTreeView *qtvExplorer;

    QGridLayout *layout;

};

#endif	/* _EXPLORERWIDGET_H */

