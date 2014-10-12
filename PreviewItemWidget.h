/* 
 * File:   PreviewItemWidget.h
 * Author: arnaudboeglin
 *
 * Created on August 4, 2009, 4:29 PM
 */

#ifndef _PREVIEWITEMWIDGET_H
#define	_PREVIEWITEMWIDGET_H

#include <QtGui/QWidget>
#include <QtGui/QImage>
#include <QtGui/QPaintEvent>

class PreviewItemWidget : public QWidget {

    Q_OBJECT
    
public:
    
    PreviewItemWidget(QWidget *parent = 0, Qt::WindowFlags f = 0);
    PreviewItemWidget(const PreviewItemWidget& orig);
    virtual ~PreviewItemWidget();

    void setImage(QImage *image);

protected:

    virtual void paintEvent(QPaintEvent *event);

private:

    QImage *toDisplay;

};

#endif	/* _PREVIEWITEMWIDGET_H */

