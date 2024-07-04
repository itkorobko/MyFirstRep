#include <QtWidgets>
#include <windows.h>
#if defined(QT_PRINTSUPPORT_LIB)
#endif
#define EMPTY_DRAWING 0
#define LINE_DRAWING 1
#define RECT_DRAWING 2
#define CIRCLE_DRAWING 3
#define COME_BACK_DRAWING 4
#include "scribblearea.h"
int mode= LINE_DRAWING;
ScribbleArea::ScribbleArea(QWidget *parent)
    : QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);
    modified = false;
    scribbling = false;
    myPenWidth = 1;
    myPenColor = Qt::black;
    QImage c_image=image;
    v_i.push_back(c_image);
}
bool ScribbleArea::openImage(const QString &fileName)
{
    QImage loadedImage;
    if (!loadedImage.load(fileName))
        return false;

    QSize newSize = loadedImage.size().expandedTo(size());
    resizeImage(&loadedImage, newSize);
    image = loadedImage;
    ///////////////////////////////////////////////////
    QImage c_image=image;
    v_i.push_back(c_image);
    //////////////////////////////////////////////////
    modified = false;
    update();
    return true;
}

bool ScribbleArea::saveImage(const QString &fileName, const char *fileFormat)
{
    QImage visibleImage = image;
    resizeImage(&visibleImage, size());

    if (visibleImage.save(fileName, fileFormat)) {
        modified = false;
        return true;
    } else {
        return false;
    }
}
void ScribbleArea::setPenColor(const QColor &newColor)
{
    myPenColor = newColor;
}
void ScribbleArea::setPenWidth(int newWidth)
{
    myPenWidth = newWidth;
}

void ScribbleArea::clearImage()
{
    image.fill(qRgb(255, 255, 255));
    ////////////////////////////////////////////
    QImage c_image=image;
    v_i.push_back(c_image);
    ///////////////////////////////////////////
    modified = true;
    update();
}
void ScribbleArea::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        switch(mode)
        {
        case LINE_DRAWING:
            {
                lastPoint = event->pos();
                scribbling = true;

                break;
            }
        case RECT_DRAWING:
            {
               // image_copy=image;
                startPoint=event->pos();
                scribbling=true;
                break;
            }
        case CIRCLE_DRAWING:
            {
                startPoint=event->pos();
                scribbling=true;
                break;
            }

        }
        /////////////////////////////////////////

        /////////////////////////////////
    }
}

void ScribbleArea::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && scribbling)
    {
        switch(mode)
        {
        case LINE_DRAWING:
        {

            drawLineTo(event->pos());

            break;
        }
        case RECT_DRAWING:
        {

            myEndPoint = event->pos();
            update();

          // drawRectangle(event->pos());

            break;
        }

        case CIRCLE_DRAWING:
        {

            myEndPoint = event->pos();
            update();

            // drawRectangle(event->pos());

            break;
        }
        }
    }
 //   drawLineTo(event->pos());

}
void ScribbleArea::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && scribbling) {
        switch(mode)
        {
        case LINE_DRAWING:
            {
                 drawLineTo(event->pos());

                  scribbling = false;
                 ///////////////////////////////////
                  QImage c_image=image;
                  v_i.push_back(c_image);
                 ////////////////////////////////////
                 break;
            }
        case RECT_DRAWING:
            {
                scribbling=false;
                drawRectangle(event->pos());
                //scribbling=false;
                ///////////////////////////////////
                QImage c_image=image;
                v_i.push_back(c_image);
                ////////////////////////////////////
                mode=LINE_DRAWING;
                break;
            }
        case CIRCLE_DRAWING:
        {
            scribbling=false;
            drawCircle(event->pos());
                ///////////////////////////////////
            QImage c_image=image;
            v_i.push_back(c_image);
            ////////////////////////////////////
            //scribbling=false;
            mode=LINE_DRAWING;
            break;
        }

        }
    }
}

void ScribbleArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    if(mode==LINE_DRAWING)
    painter.drawImage(QPoint(0, 0), image);
    else
    painter.drawImage(QPoint(0, 0), v_i[v_i.size()-1]);

    if(mode==COME_BACK_DRAWING)
        mode=LINE_DRAWING;
  //  QRect dirtyRect = event->rect();
    //painter.drawImage(dirtyRect, image, dirtyRect);

    if (scribbling && mode == RECT_DRAWING) {
        // Рисуем прямоугольник в режиме рисования
        painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        QRect rect(startPoint, myEndPoint);
        painter.drawRect(rect.normalized());
    }
    if (scribbling && mode == CIRCLE_DRAWING) {
        // Рисуем прямоугольник в режиме рисования
        painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        QRect rect(startPoint, myEndPoint);
        painter.drawEllipse(rect.normalized());
    }
}
void ScribbleArea::resizeEvent(QResizeEvent *event)
{
    if (width() > image.width() || height() > image.height()) {
        int newWidth = qMax(width() + 128, image.width());
        int newHeight = qMax(height() + 128, image.height());
        resizeImage(&image, QSize(newWidth, newHeight));

        update();
    }
    QWidget::resizeEvent(event);
}

void ScribbleArea::drawLineTo(const QPoint &endPoint)
{
    QPainter painter(&image);
  //  QPainter painter(&v_i[v_i.size()-1]);
    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));
    painter.drawLine(lastPoint, endPoint);
    modified = true;

    int rad = (myPenWidth / 2) + 2;
    update(QRect(lastPoint, endPoint).normalized()
               .adjusted(-rad, -rad, +rad, +rad));
    lastPoint = endPoint;
}
void ScribbleArea::drawRectangle(const QPoint &endPoint)
{

     QPainter painter(&image);

    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.drawRect(startPoint.x(),startPoint.y(),endPoint.x()-startPoint.x(), endPoint.y()-startPoint.y());
    modified = true;
    update(QRect(QPoint(0,0), QPoint(1280,760)).normalized());


}
void ScribbleArea::drawCircle(const QPoint &endPoint)
{

    QPainter painter(&image);
    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
   // painter.drawRect(startPoint.x(),startPoint.y(),endPoint.x()-startPoint.x(), endPoint.y()-startPoint.y());
    painter.drawEllipse(startPoint.x(),startPoint.y(),endPoint.x()-startPoint.x(), endPoint.y()-startPoint.y());
    modified = true;
    update(QRect(QPoint(0,0), QPoint(1280,760)).normalized());


}
void ScribbleArea::resizeImage(QImage *image, const QSize &newSize)
{

    if (image->size() == newSize)
        return;
    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}
void ScribbleArea::makeRect()
{
    mode=RECT_DRAWING;
}
void ScribbleArea::makeCircle()
{
    mode=CIRCLE_DRAWING;
}
void ScribbleArea::makeComeBack()
{
    mode=COME_BACK_DRAWING;
    if(v_i.size()>2)
    {  v_i.pop_back();
    image=v_i[v_i.size()-1];
    modified = true;
    update(QRect(QPoint(0,0), QPoint(1280,760)).normalized());
    }
    else if(v_i.size()==2)
    {
        clearImage();
    }
    mode=LINE_DRAWING;

}
