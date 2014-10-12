/* 
 * File:   MainWindow.h
 * Author: arnaudboeglin
 *
 * Created on August 2, 2009, 9:58 PM
 */

#ifndef _MAINWINDOW_H
#define	_MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QtGui/QDockWidget>

#include "KEWidget.h"
#include "ItemsWidget.h"
#include "FileDelegate.h"
#include "ExplorerWidget.h"

class MainWindow : public QMainWindow {

    Q_OBJECT

public:

    MainWindow(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    virtual ~MainWindow();

public slots:

    
    
private:

    MainWindow(const MainWindow& orig);

    void createMenus();
    void createActions();
    void createMainToolBar();

    /**
     * Menu file :
     */
    QAction *actQuit;
    QAction *actNew;
    QAction *actOpen;
    QAction *actSave;
    QAction *actSaveAs;
    QAction *actClose;

    /**
     * Menu edit :
     */
    QAction *actUndo;
    QAction *actRedo;
    QAction *actCopy;
    QAction *actCut;
    QAction *actPaste;
    QAction *actDeselect;
    QAction *actSelectAll;

    /**
     * Menu tools :
     */
    QAction *actOptions;

    /**
     * Menu windows :
     */
    //TODO:

    /**
     * Menu help :
     */
    QAction *actAbout;


    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuTools;
    QMenu *menuWindows;
    QMenu *menuHelp;

    QMenuBar *menuBar;
    QToolBar *toolBar;


    QDockWidget *itemsDock;
    ItemsWidget *itemsPanel;
    KEWidget *editor;

    QDockWidget *explorerDock;
    ExplorerWidget *explorer;

    FileDelegate *fileDelegate;

private slots:

    void openFile();
    void openFileDialog();
    void save();
    void saveAs();
    void newFile();
    void closeFile();
    void undo();
    void redo();
    void copy();
    void paste();
    void cut();
    void deselect();
    void selectAll();
    void showOptions();
    void showAbout();

};

#endif	/* _MAINWINDOW_H */

