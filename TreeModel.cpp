/* 
 * File:   TreeModel.cpp
 * Author: jonas
 * 
 * Created on 7 décembre 2009, 22:23
 */

#include <qt4/QtGui/qpictureformatplugin.h>

#include "TreeModel.h"

TreeModel::TreeModel(const QStringList &headers, const QString &data, QObject *parent) : QAbstractItemModel(parent) {
//    QVector<QVariant> rootData;
//    foreach(QString header, headers)
//    rootData << header;
//
//    rootItem = new TreeItem(rootData);
//    setupModelData(data.split(QString("\n")), rootItem);
}

TreeModel::~TreeModel() {
    delete rootItem;
}

//Pour le moment, on fonctionne avec 3 colonnes.
int TreeModel::columnCount(const QModelIndex & /* parent */) const {
//    return rootItem->columnCount();
    return 3;
}

/*D'aprés ce que j'ai compris, avec l'index on trouve notre element, puis dedans on a la colonne souhaitée, qui correspond
 * aux infos de la colonne qu'on veut.
 * Pour test, on part sur 3 colonnes :
 * Nom | PosX | Visible
 */
QVariant TreeModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole && role != Qt::EditRole)
        return QVariant();

    ke::DrawableNode *item = getItem(index);

//        return item->data(index.column());
    if(index.column() == 0)
        return "Objet";
    else if(index.column() == 1)
        return item->getPosX();
    else if(index.column() == 2)
        return item->getOpacity();
}

//TODO: mettre les bons flags. Les trouver, d'abord
Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const {
    if (!index.isValid())
        return 0;

    return Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

//TODO: Revoir le fonctionnement de la fonction, pas compris grand chose..
ke::DrawableNode *TreeModel::getItem(const QModelIndex &index) const {
    if (index.isValid()) {
        ke::DrawableNode *item = static_cast<ke::DrawableNode*> (index.internalPointer());
        if (item) return item;
    }
    return rootItem;
}

/* Bon, voici le fonctionnement de la chose:
 * La fonction doit renvoyer ce qui sera affiché dans l'êntête de la colonne nº section,
 * En gros, si l'arbre a 3 colonnes, Nom, X, Visible, ben si section = 2, la fonction doit renvoyer "Visible".
 * Mais, d'aprés ce que j'ai compris, on affiche que les header du rootItem, donc bon..
 */
QVariant TreeModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole){
//        return rootItem->data(section);
        if(section == 0)
            return "Name";
        else if(section == 1)
            return "PosX";
        else if(section == 2)
            return "Visible";
    }
    return QVariant();
}

//TODO: check si c'est ok. Toujours chelou le getItem..
QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const {
    if (parent.isValid() && parent.column() != 0)
        return QModelIndex();

    ke::DrawableNode *parentItem = getItem(parent);

    ke::DrawableNode *childItem = parentItem->getChild(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

// //Car bon, l'ajout de colonnes, ça sera pour la V2 hein..
//bool TreeModel::insertColumns(int position, int columns, const QModelIndex &parent) {
//    bool success;
//
//    beginInsertColumns(parent, position, position + columns - 1);
//    success = rootItem->insertColumns(position, columns);
//    endInsertColumns();
//
//    return success;
//}

/*Bon alors:
 * En gros, ça rajoute des lignes vides. 
 * Dans notre cas, des drawableNodes Vides. 
 * Nodes qu'il faudra remplir par la suite. Pour y acceder, ben on y va avec les indices.
 * Ça insère 'rows' fils avant le fils nº "position", pour le parent donné en index.
 */
bool TreeModel::insertRows(int position, int rows, const QModelIndex &parent) {
    ke::DrawableNode *parentItem = getItem(parent);
    bool success;

    beginInsertRows(parent, position, position + rows - 1);
//    success = parentItem->insertChildren(position, rows, rootItem->columnCount());
//    parentItem->add(new ke::DrawableNode);
    endInsertRows();

    return success;
}

//TODO: remplacer avec la fonction qui donne le nb d'enfants
QModelIndex TreeModel::parent(const QModelIndex &index) const {
    if (!index.isValid())
        return QModelIndex();

    ke::DrawableNode *childItem = getItem(index);
    ke::DrawableNode *parentItem = childItem->getParent();

    if (parentItem == rootItem)
        return QModelIndex();

//    return createIndex(parentItem->childNumber(), 0, parentItem);
}

//bool TreeModel::removeColumns(int position, int columns, const QModelIndex &parent) {
//    bool success;
//
//    beginRemoveColumns(parent, position, position + columns - 1);
//    success = rootItem->removeColumns(position, columns);
//    endRemoveColumns();
//
//    if (rootItem->columnCount() == 0)
//        removeRows(0, rowCount());
//
//    return success;
//}

//TODO: revoir la boucle, voir si elle enleve les bons. Ptete pb d'indexs
bool TreeModel::removeRows(int position, int rows, const QModelIndex &parent) {
    ke::DrawableNode *parentItem = getItem(parent);
    bool success = true;

    beginRemoveRows(parent, position, position + rows - 1);
//    success = parentItem->removeChildren(position, rows);

    for (int i = 0; i < rows; i++)
        parentItem->remove(parentItem->getChild(position + i));

    endRemoveRows();

    return success;
}

//TODO: besoin fonction nb enfants
int TreeModel::rowCount(const QModelIndex &parent) const {
    ke::DrawableNode *parentItem = getItem(parent);

//    return parentItem->childCount();
}

bool TreeModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (role != Qt::EditRole)
        return false;

    ke::DrawableNode *item = getItem(index);
//    bool result = item->setData(index.column(), value);
    
    bool *result;

    if(index.column() == 1)
        item->setPosition(value.toDouble(result), item->getPosY());
    else if(index.column() == 2)
        item->setOpacity(value.toDouble(result));

    

    if (result)
        emit dataChanged(index, index);

    return result;
}

//bool TreeModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role) {
//    if (role != Qt::EditRole || orientation != Qt::Horizontal)
//        return false;
//
//    bool result = rootItem->setData(section, value);
//
//    if (result)
//        emit headerDataChanged(orientation, section, section);
//
//    return result;
//}

// void TreeModel::setupModelData(const QStringList &lines, TreeItem *parent)
// {
//     QList<TreeItem*> parents;
//     QList<int> indentations;
//     parents << parent;
//     indentations << 0;
//
//     int number = 0;
//
//     while (number < lines.count()) {
//         int position = 0;
//         while (position < lines[number].length()) {
//             if (lines[number].mid(position, 1) != " ")
//                 break;
//             position++;
//         }
//
//         QString lineData = lines[number].mid(position).trimmed();
//
//         if (!lineData.isEmpty()) {
//             // Read the column data from the rest of the line.
//             QStringList columnStrings = lineData.split("\t", QString::SkipEmptyParts);
//             QVector<QVariant> columnData;
//             for (int column = 0; column < columnStrings.count(); ++column)
//                 columnData << columnStrings[column];
//
//             if (position > indentations.last()) {
//                 // The last child of the current parent is now the new parent
//                 // unless the current parent has no children.
//
//                 if (parents.last()->childCount() > 0) {
//                     parents << parents.last()->child(parents.last()->childCount()-1);
//                     indentations << position;
//                 }
//             } else {
//                 while (position < indentations.last() && parents.count() > 0) {
//                     parents.pop_back();
//                     indentations.pop_back();
//                 }
//             }
//
//             // Append a new item to the current parent's list of children.
//             TreeItem *parent = parents.last();
//             parent->insertChildren(parent->childCount(), 1, rootItem->columnCount());
//             for (int column = 0; column < columnData.size(); ++column)
//                 parent->child(parent->childCount() - 1)->setData(column, columnData[column]);
//         }
//
//         number++;
//     }
// }

