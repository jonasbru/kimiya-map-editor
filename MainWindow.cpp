/* 
 * File:   MainWindow.cpp
 * Author: arnaudboeglin
 * 
 * Created on August 2, 2009, 9:58 PM
 */

#include "MainWindow.h"
#include "Director.h"
#include "ItemsWidget.h"

#include <QtGui/QMenuBar>
#include <QtGui/QMenu>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QToolBar>
#include <QtGui/QFileDialog>
#include <QtGui/qmessagebox.h>

#include <iostream>


MainWindow::MainWindow(QWidget *parent, Qt::WindowFlags flags) : QMainWindow(parent, flags) {
    this->editor = new KEWidget(this);
    this->setCentralWidget(this->editor);

    this->setMinimumSize(640, 480);

    this->createMenus();
    this->createActions();
    this->createMainToolBar();

    this->itemsDock = new QDockWidget(this);
    this->itemsPanel = new ItemsWidget(this);
    this->itemsDock->setWidget(this->itemsPanel);
    this->addDockWidget(Qt::LeftDockWidgetArea, this->itemsDock);
    this->itemsDock->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
    this->itemsDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);


    this->explorer = new ExplorerWidget(this);
    this->explorerDock = new QDockWidget(this);
    this->explorerDock->setWidget(this->explorer);
    this->addDockWidget(Qt::RightDockWidgetArea, this->explorerDock);
    this->explorerDock->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
    this->explorerDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    this->fileDelegate = new FileDelegate();


}

MainWindow::MainWindow(const MainWindow& orig){
    
}

MainWindow::~MainWindow() {
    delete this->menuBar;
}

void MainWindow::createMenus(){
    this->menuBar = new QMenuBar();
    this->setMenuBar(this->menuBar);

    this->menuFile = new QMenu("File", this);
    this->menuEdit = new QMenu("Edit", this);
    this->menuTools = new QMenu("Tools", this);
    this->menuWindows = new QMenu("Windows", this);
    this->menuHelp = new QMenu("Help");

    this->menuBar->addMenu(this->menuFile);
    this->menuBar->addMenu(this->menuEdit);
    this->menuBar->addMenu(this->menuTools);
    this->menuBar->addMenu(this->menuWindows);
    this->menuBar->addMenu(this->menuHelp);
}

void MainWindow::createActions(){

    /**
     * Icons :
     */
    QIcon icUndo("icons/undo.ico");
    QIcon icRedo("icons/redo.ico");
    QIcon icOpen("icons/open.ico");
    QIcon icSave("icons/save.ico");
    QIcon icClose("icons/close.ico");

    QIcon icCut("icons/cut.png");
    QIcon icCopy("icons/copy.png");
    QIcon icPaste("icons/paste.ico");

    /**
     * Menu file :
     */
    this->actNew = new QAction("New", this);
    this->actOpen = new QAction(icOpen, "Open", this);
    this->actSave = new QAction(icSave, "Save", this);
    this->actSaveAs = new QAction(icSave, "Save as", this);
    this->actClose = new QAction(icClose, "Close", this);
    this->actQuit = new QAction("Quit", this);

    this->actNew->setMenuRole(QAction::NoRole);
    this->actOpen->setMenuRole(QAction::NoRole);
    this->actSave->setMenuRole(QAction::NoRole);
    this->actSaveAs->setMenuRole(QAction::NoRole);
    this->actClose->setMenuRole(QAction::NoRole);
    this->actQuit->setMenuRole(QAction::NoRole);

    this->menuFile->addAction(this->actNew);
    this->menuFile->addSeparator();
    this->menuFile->addAction(this->actOpen);
    this->menuFile->addSeparator();
    this->menuFile->addAction(this->actSave);
    this->menuFile->addAction(this->actSaveAs);
    this->menuFile->addSeparator();
    this->menuFile->addAction(this->actClose);
    this->menuFile->addSeparator();
    this->menuFile->addAction(this->actQuit);

    QObject::connect(this->actNew, SIGNAL(triggered()), this, SLOT(newFile()));
    QObject::connect(this->actOpen, SIGNAL(triggered()), this, SLOT(openFile()));
    QObject::connect(this->actSave, SIGNAL(triggered()), this, SLOT(save()));
    QObject::connect(this->actSaveAs, SIGNAL(triggered()), this, SLOT(saveAs()));
    QObject::connect(this->actClose, SIGNAL(triggered()), this, SLOT(closeFile()));
    QObject::connect(this->actQuit, SIGNAL(triggered()), qApp, SLOT(quit()));

    /**
     * Menu edit :
     */
    this->actUndo = new QAction(icUndo, "Undo", this);
    this->actRedo = new QAction(icRedo, "Redo", this);
    this->actCopy = new QAction(icCopy, "Copy", this);
    this->actCut = new QAction(icCut, "Cut", this);
    this->actPaste = new QAction(icPaste, "Paste", this);
    this->actDeselect = new QAction("Deselect", this);
    this->actSelectAll = new QAction("SelectAll", this);

    this->actUndo->setMenuRole(QAction::NoRole);
    this->actRedo->setMenuRole(QAction::NoRole);
    this->actCopy->setMenuRole(QAction::NoRole);
    this->actCut->setMenuRole(QAction::NoRole);
    this->actPaste->setMenuRole(QAction::NoRole);
    this->actDeselect->setMenuRole(QAction::NoRole);
    this->actSelectAll->setMenuRole(QAction::NoRole);

    this->menuEdit->addAction(this->actUndo);
    this->menuEdit->addAction(this->actRedo);
    this->menuEdit->addSeparator();
    this->menuEdit->addAction(this->actCopy);
    this->menuEdit->addAction(this->actCut);
    this->menuEdit->addAction(this->actPaste);
    this->menuEdit->addSeparator();
    this->menuEdit->addAction(this->actDeselect);
    this->menuEdit->addAction(this->actSelectAll);

    QObject::connect(this->actUndo, SIGNAL(triggered()), this, SLOT(undo()));
    QObject::connect(this->actRedo, SIGNAL(triggered()), this, SLOT(redo()));
    QObject::connect(this->actCopy, SIGNAL(triggered()), this, SLOT(copy()));
    QObject::connect(this->actCut, SIGNAL(triggered()), this, SLOT(cut()));
    QObject::connect(this->actPaste, SIGNAL(triggered()), this, SLOT(paste()));
    QObject::connect(this->actDeselect, SIGNAL(triggered()), this, SLOT(deselect()));
    QObject::connect(this->actSelectAll, SIGNAL(triggered()), this, SLOT(selectAll()));

    /**
     * Menu tools :
     */
    this->actOptions = new QAction("Options", this);

    this->actOptions->setMenuRole(QAction::NoRole);

    this->menuTools->addAction(this->actOptions);

    QObject::connect(this->actOptions, SIGNAL(triggered()), this, SLOT(showOptions()));

    /**
     * Menu windows :
     */
    //TODO:

    /**
     * Menu help :
     */
    this->actAbout = new QAction("About", this);

    this->actAbout->setMenuRole(QAction::NoRole);

    this->menuHelp->addAction(this->actAbout);

    QObject::connect(this->actAbout, SIGNAL(triggered()), this, SLOT(showAbout()));
    
//    connect(a, SIGNAL(triggered()), qApp, SLOT(quit()));
}

void MainWindow::createMainToolBar(){
    this->toolBar = new QToolBar(this);
    this->addToolBar(this->toolBar);
    
    this->toolBar->setAllowedAreas(Qt::TopToolBarArea);
    this->toolBar->setFloatable(false);
    this->toolBar->setMovable(false);

    this->toolBar->addAction(this->actOpen);
    this->toolBar->addSeparator();
    this->toolBar->addAction(this->actSave);
    this->toolBar->addAction(this->actSaveAs);
    this->toolBar->addSeparator();
    this->toolBar->addAction(this->actClose);
    this->toolBar->addSeparator();
    this->toolBar->addAction(this->actCopy);
    this->toolBar->addAction(this->actCut);
    this->toolBar->addAction(this->actPaste);
    this->toolBar->addSeparator();
    this->toolBar->addAction(this->actUndo);
    this->toolBar->addAction(this->actRedo);
}

void MainWindow::openFile(){

    QString fileName = QFileDialog::getOpenFileName(0, tr("Open File"), tr("/home"), QString(), 0, QFileDialog::DontUseNativeDialog);

    this->fileDelegate->loadAll(fileName.toStdString());
}

void MainWindow::openFileDialog(){

}

void MainWindow::save(){

}

void MainWindow::saveAs(){

}

void MainWindow::newFile(){

}

void MainWindow::closeFile(){

}

void MainWindow::undo(){

}

void MainWindow::redo(){

}

void MainWindow::copy(){

}

void MainWindow::paste(){

}

void MainWindow::cut(){

}

void MainWindow::deselect(){

}

void MainWindow::selectAll(){
    
}

void MainWindow::showOptions(){

}

void MainWindow::showAbout(){
    
}

