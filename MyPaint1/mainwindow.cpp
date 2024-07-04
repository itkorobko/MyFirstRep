#include <QtWidgets>

#include "mainwindow.h"
#include "scribblearea.h"
MainWindow::MainWindow()
{
    scribbleArea = new ScribbleArea;
    setCentralWidget(scribbleArea);
    createActions();
    createMenus();
    setWindowTitle(tr("СуперРисовалка"));
    resize(500, 500);
}
void MainWindow::closeEvent(QCloseEvent *event)
{
    if (maybeSave()) {
        event->accept();
    }
    else {
        event->ignore();
    }
}
void MainWindow::open()
{
    if (maybeSave()) {
        QString fileName = QFileDialog::getOpenFileName(this,
                tr("Открыть файл"), QDir::currentPath());
        if (!fileName.isEmpty())
            scribbleArea->openImage(fileName);
    }
}
void MainWindow::save()
{
    QAction *action = qobject_cast<QAction *>(sender());
    QByteArray fileFormat = action->data().toByteArray();
    saveFile(fileFormat);
}
void MainWindow::penColor()
{
    QColor newColor = QColorDialog::getColor(scribbleArea->penColor());
    if (newColor.isValid())
        scribbleArea->setPenColor(newColor);
}

void MainWindow::penWidth()
{
    bool ok;
    int newWidth = QInputDialog::getInt(this, tr("СуперРисовалка"),
                                        tr("Тощина стержня:"),
                                        scribbleArea->penWidth(),
                                        1, 50, 1, &ok);
    if (ok)
        scribbleArea->setPenWidth(newWidth);
}
void MainWindow::about()
{
    QMessageBox::about(this, tr("О приложении"),
                       tr("Это приложение напоминает Paint"));
}
void MainWindow::createActions()
{
    openAct = new QAction(tr("Открыть"), this);
    openAct->setShortcuts(QKeySequence::Open);
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));
    foreach (QByteArray format, QImageWriter::supportedImageFormats()) {
        QString text = tr("%1...").arg(QString(format).toUpper());
        QAction *action = new QAction(text, this);
        action->setData(format);
        connect(action, SIGNAL(triggered()), this, SLOT(save()));
        saveAsActs.append(action);
    }
    exitAct = new QAction(tr("Выход"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
    penColorAct = new QAction(tr("Цвет стержня"), this);
    connect(penColorAct, SIGNAL(triggered()), this, SLOT(penColor()));
    penWidthAct = new QAction(tr("Тощина стержня"), this);
    connect(penWidthAct, SIGNAL(triggered()), this, SLOT(penWidth()));
    clearScreenAct = new QAction(tr("Очистить экран"), this);
    clearScreenAct->setShortcut(tr("Ctrl+L"));
    connect(clearScreenAct, SIGNAL(triggered()),
            scribbleArea, SLOT(clearImage()));
    /////////////////////////////////////////////////////////////////
    drawRect=new QAction(tr("Прямоугольник"),this);
    connect(drawRect,SIGNAL(triggered()),this, SLOT(rectChosen()));
    circleAct=new QAction(tr("Эллипс"),this);
    connect(circleAct,SIGNAL(triggered()),this, SLOT(circleChosen()));
    comeBackAct=new QAction(tr("Отменить"),this);
    connect(comeBackAct,SIGNAL(triggered()),this, SLOT(comeBackChosen()));
    ////////////////////////////////////////////////////////////
    aboutAct = new QAction(tr("О приложении"), this);
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
}
void MainWindow::createMenus()
{
    saveAsMenu = new QMenu(tr("Сохранить как"), this);
    foreach (QAction *action, saveAsActs)
        saveAsMenu->addAction(action);
    fileMenu = new QMenu(tr("Файл"), this);
    fileMenu->addAction(openAct);
    fileMenu->addMenu(saveAsMenu);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);
    optionMenu = new QMenu(tr("Параметры"), this);
    optionMenu->addAction(penColorAct);
    optionMenu->addAction(penWidthAct);
     optionMenu->addAction(comeBackAct);
    optionMenu->addSeparator();
    optionMenu->addAction(clearScreenAct);
    /////////////////////////////////////////////////////////
    chooseFigure=new QMenu(tr("Выбор фигуры"),this);
    chooseFigure->addAction(drawRect);
    chooseFigure->addAction(circleAct);
    ////////////////////////////////////////////////////////
    helpMenu = new QMenu(tr("Помощь"), this);
    helpMenu->addAction(aboutAct);
    menuBar()->addMenu(fileMenu);
    menuBar()->addMenu(optionMenu);
    menuBar()->addMenu(chooseFigure);
    menuBar()->addMenu(helpMenu);
}

bool MainWindow::maybeSave()
{
    if (scribbleArea->isModified()) {
        QMessageBox::StandardButton ret;
        ret = QMessageBox::warning(this, tr("СуперРисовалка"),
                                   tr("Сохранить изменения?"),
                                   QMessageBox::Yes | QMessageBox::No);
        if (ret == QMessageBox::Yes) {
            return saveFile("png");
        } else if (ret == QMessageBox::No) {
            this->close();
        }
    }
    return true;
}

bool MainWindow::saveFile(const QByteArray &fileFormat)
{
    QString initialPath = QDir::currentPath() + "/untitled." + fileFormat;
    QString fileName = QFileDialog::getSaveFileName(this, tr("Сохранить как"),initialPath,
             tr("%1 Files (*.%2);;All Files (*)")
            .arg(QString::fromLatin1(fileFormat.toUpper()))
            .arg(QString::fromLatin1(fileFormat)));
    if (fileName.isEmpty()) {
        return false;
    } else {
        return scribbleArea->saveImage(fileName, fileFormat.constData());
    }
}
void MainWindow::rectChosen()
{
    scribbleArea->makeRect();
}
void MainWindow::circleChosen()
{
    scribbleArea->makeCircle();
}
void MainWindow::comeBackChosen()
{
    scribbleArea->makeComeBack();
}
