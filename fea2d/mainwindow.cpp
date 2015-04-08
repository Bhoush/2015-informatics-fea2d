#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "Exception.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
    {
    ui->setupUi(this);
    connect(ui->action_Open, SIGNAL(triggered()), SLOT(openFile()) );
    connect(ui->action_Quit, SIGNAL(triggered()), SLOT(close()) );

    setCentralWidget(m_visualizer = new Visualizer2d);
    m_visualizer->setDocument(&m_doc);
    }

MainWindow::~MainWindow()
    {
    delete ui;
    }

void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open document"), QString(), "fea2d (*.fea2d);;XML files (*.xml)");
    if(fileName.isEmpty())
        return;

    // Load document from file
    try {
        m_doc.read(fileName);
    }
    catch(Exception& e) {
        QMessageBox::critical(this, QString(), e.what());
    }
}
