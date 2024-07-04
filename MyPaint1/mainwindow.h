#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QList>
#include <QMainWindow>

class ScribbleArea;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

protected:

    void closeEvent(QCloseEvent *event) override;

    // The events that can be triggered
private slots:
    void open();
    void save();
    void penColor();
    void penWidth();
    void about();
    void comeBackChosen();
    void rectChosen();
    void circleChosen();

private:
    // Will tie user actions to functions
    void createActions();
    void createMenus();

    // Will check if changes have occurred since last save
    bool maybeSave();

    // Opens the Save dialog and saves
    bool saveFile(const QByteArray &fileFormat);

    // What we'll draw on
    ScribbleArea *scribbleArea;

    // The menu widgets
    QMenu *saveAsMenu;
    QMenu *fileMenu;
    QMenu *optionMenu;
    QMenu *helpMenu;
    QMenu *chooseFigure;
    // All the actions that can occur
    QAction *openAct;
    QAction *drawRect;
    QAction *circleAct;
    // Actions tied to specific file formats
    QList<QAction *> saveAsActs;
    QAction *exitAct;
    QAction *penColorAct;
    QAction *penWidthAct;
    QAction *comeBackAct;
    QAction *clearScreenAct;
    QAction *aboutAct;

};

#endif
