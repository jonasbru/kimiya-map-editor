/* 
 * File:   ItemsWidget.h
 * Author: arnaudboeglin
 *
 * Created on August 3, 2009, 9:42 PM
 */

#ifndef _ITEMSWIDGET_H
#define	_ITEMSWIDGET_H

#include <QtGui/QWidget>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtCore/QMap>
#include <QtCore/QList>
#include <QtCore/QPair>
#include <QtCore/QString>

#include "PreviewItemWidget.h"

Q_DECLARE_METATYPE(QImage*);

static const QString RESSOURCES_PATH("ressources/");

class ItemsWidget : public QWidget {

    Q_OBJECT

public:

    ItemsWidget(QWidget *parent = 0, Qt::WindowFlags f = 0);
    ItemsWidget(const ItemsWidget& orig);
    virtual ~ItemsWidget();
    
private:

    void loadItems();

    QComboBox *qcbItemThemes;
    QComboBox *qcbItems;
    PreviewItemWidget *preview;

    QGridLayout *layout;

    QMap<QString, QList<QPair<QString, QImage*> > > items;

private slots:

    void itemThemeHasChanged(int newIndex);
    void itemHasChanged(int newIndex);

};

#endif	/* _ITEMSWIDGET_H */

