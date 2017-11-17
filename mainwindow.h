#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ViewWidget.h>

using namespace kee;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initActions();

private slots:
    void onOpenFileAction();

private:
    Ui::MainWindow *ui;
    ViewWidget * m_viewWidget;

    QAction* m_openFileAction;
};

#endif // MAINWINDOW_H
