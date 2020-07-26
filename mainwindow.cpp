#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <fstream>
#include <vector>
#include <QDir>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    produceUpdateAndRenderImage();
}

void MainWindow::produceUpdateAndRenderImage()
{
    updateDotFile();
    updateImage();
    renderImage();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateDotFile()
{
    std::ofstream myFile;
    QDir::setCurrent(QCoreApplication::applicationFilePath());
    myFile.open
    (
        "file.dot"
    );

    std::string textToFile;
    if (ui->radioButtonLayoutImproved->isChecked())
        textToFile = fibonacciHeap.getDrawModeTwo();
    else
        textToFile = fibonacciHeap.getDrawModeOne();

    myFile << textToFile;
    myFile.close();
}

void MainWindow::updateImage()
{
    std::string message =
                "dot -Tpng file.dot > file.png";
    QDir::setCurrent(QCoreApplication::applicationFilePath());
    system(message.c_str());
}

void MainWindow::renderImage()
{
    QDir::setCurrent(QCoreApplication::applicationFilePath());
    QPixmap image("file.png");
    ui->labelOfImage->setPixmap(image);
    ui->labelOfImage->show();
}


void MainWindow::on_pushButton_clicked()
{
    std::string data = ui->lineEditHead->text().toStdString();
    fibonacciHeap.insertBeforeStart(std::atoi(data.c_str()));

    produceUpdateAndRenderImage();
}

void MainWindow::on_pushButton_3_clicked()
{
    FibonacciHeapNode* removed = fibonacciHeap.deleteMinInterface();
    delete removed;

    produceUpdateAndRenderImage();
}

void MainWindow::on_pushButtonOfSearch_clicked()
{
    std::string data = ui->lineEditOfSearch->text().toStdString();
    FibonacciHeapNode* ret = fibonacciHeap.search(std::atoi(data.c_str()));

    QMessageBox msgBox;
    msgBox.setText(ret != nullptr? "This node exists": "This node DOES NOT exist");
    msgBox.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    std::string dec = ui->lineEditOfDecrement->text().toStdString();
    std::string dataKey = ui->lineEditOfDecreaseKey->text().toStdString();
    bool ret = fibonacciHeap.decrementKey
    (
        std::atoi(dataKey.c_str()), //key
        std::atoi(dec.c_str())      //decremento
    );

    if (ret != false)
    {
        produceUpdateAndRenderImage();

        QMessageBox msgBox;
        msgBox.setText("Heap updated");
        msgBox.exec();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("There is not a node with this key");
        msgBox.exec();
    }
}

void MainWindow::on_radioButtonLayoutImproved_toggled(bool checked)
{
    produceUpdateAndRenderImage();
}
