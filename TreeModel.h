/* 
 * File:   TreeModel.h
 * Author: jonas
 *
 * Created on 7 décembre 2009, 22:23
 */

#ifndef _TREEMODEL_H
#define	_TREEMODEL_H

#include "lib/include/Layer.h"

 #include <QtCore/QAbstractItemModel>
 #include <QtCore/QModelIndex>
 #include <QtCore/QVariant>


class TreeModel : public QAbstractItemModel {
    
public:

    //    TreeModel();
    //    TreeModel(const TreeModel& orig);
    //    virtual ~TreeModel();

    TreeModel(const QStringList &headers, const QString &data, QObject *parent = 0);
    ~TreeModel();

    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &index) const;

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
//    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole);

//    bool insertColumns(int position, int columns, const QModelIndex &parent = QModelIndex());
//    bool removeColumns(int position, int columns, const QModelIndex &parent = QModelIndex());
    bool insertRows(int position, int rows, const QModelIndex &parent = QModelIndex());
    bool removeRows(int position, int rows, const QModelIndex &parent = QModelIndex());

private:

//    void setupModelData(const QStringList &lines, TreeItem *parent);
//    TreeItem *getItem(const QModelIndex &index) const;
//
//    TreeItem *rootItem;

    ke::DrawableNode *getItem(const QModelIndex &index) const;

    ke::Layer *rootItem;

};

#endif	/* _TREEMODEL_H */

