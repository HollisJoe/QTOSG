#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //init actions
    initActions();

    //init view
    m_viewWidget=new ViewWidget(this);
    this->setCentralWidget(m_viewWidget);
}

MainWindow::~MainWindow()
{
    delete m_viewWidget;
    m_viewWidget=NULL;

    delete ui;
}

void MainWindow::initActions()
{
    m_openFileAction=new QAction(tr("Open"),this);
    connect(m_openFileAction,SIGNAL(triggered()),this,SLOT(onOpenFileAction()));

    QMenu* fileMenu=this->menuBar()->addMenu(tr("File"));
    fileMenu->addAction(m_openFileAction);
}


void MainWindow::onOpenFileAction()
{
    char * homePath=getenv("HOME");
    QString selectFile;
    selectFile=QFileDialog::getOpenFileName(this,tr("Open OSG File"),QString(homePath));
    if(!selectFile.isEmpty())
    {
        m_viewWidget->readNodeFromFile(selectFile.toStdString());

    }
}
