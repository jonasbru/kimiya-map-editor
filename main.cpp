/*
 * File:   main.cpp
 * Author: arnaudboeglin
 *
 * Created on July 30, 2009, 9:23 PM
 */

/**
 * TODO: MAPEDITOR
 *
 *  -Revoir le menu.
 *  -Gérer le glisser-déposer d'une image previewed.
 *  -Lecture/Ecriture de fichiers maps (voir éventuellement un xml temporaire).
 *  -Gérer les couches [ Gestion à la photoshop des levels ( niveaux ). ]
 *  -Gérer les calques [ Gestion à la photoshop des calques ( mise à jour du contenu en fonction du level selectionné ) ].
 *  -Gérer la selection des items [ Avec fenêtre de propriétées de l'objet ].
 *  -Gérer le drag & drop d'un élément déjà dans la scène.
 *  -Faire une toolbar ( déplacement, zoom, selection, différentes formes pour les propriétées du terrain ).
 *  -Gérer les règles.
 *  
 *  -Mettre à jour la TODO !
 */


#include <QtGui/QApplication>
#include <QtGui/QPushButton>
#include <QtOpenGL/QGLWidget>
#include <Layer.h>

#include "KEWidget.h"
#include "MainWindow.h"
#include "MapLoader.h"
#include "FileDelegate.h"

#include <Director.h>
#include <Sprite.h>

#include <tinyxml.h>
#include <iostream>


int main(int argc, char *argv[]) {    
    QApplication app(argc, argv);

    MainWindow m;
    m.show();

//    FileDelegate *fd = new FileDelegate();
//    fd->loadAll();

    app.exec();
    return EXIT_SUCCESS;
}
