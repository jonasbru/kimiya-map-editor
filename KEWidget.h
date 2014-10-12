/* 
 * File:   KEWidget.h
 * Author: arnaudboeglin
 *
 * Created on July 31, 2009, 12:38 PM
 */

#ifndef _KEWIDGET_H
#define	_KEWIDGET_H

#include <QtOpenGL/QGLWidget>

class KEWidget : public QGLWidget {

    Q_OBJECT

public:

    KEWidget(QWidget *parent = 0, const QGLWidget *shareWidget = 0, Qt::WindowFlags f = 0);
    KEWidget(QGLContext *context, QWidget *parent = 0, const QGLWidget *shareWidget = 0, Qt::WindowFlags f = 0);
    KEWidget(const QGLFormat &format, QWidget *parent = 0, const QGLWidget *shareWidget = 0, Qt::WindowFlags f = 0);
    
    virtual ~KEWidget();
    
protected:

    virtual void initializeGL();
    virtual void resizeGL(int width, int height);
    virtual void paintGL();

    virtual void keyPressEvent(QKeyEvent *e);

    virtual void timeOut();

private:

    KEWidget(const KEWidget& orig);

};

#endif	/* _KEWIDGET_H */

