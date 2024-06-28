#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QStandardItemModel>
#include<QTableView>
#include<QString>
#include <QAxObject>
#include<QDebug>
#include "header/xlsxdocument.h"
#include "header/xlsxchartsheet.h"
#include "header/xlsxcellrange.h"
#include "header/xlsxchart.h"
#include "header/xlsxrichstring.h"
#include "header/xlsxworkbook.h"
using namespace QXlsx;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

 //  QStandardItemModel* model=new QStandardItemModel(MyRows,MyColumns);
  //  ui->tableView->setModel(model);

}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    if(arg1.toInt())
    {
        int Cols=1;
        if(ui->lineEdit_2->text().toInt())
        {
            Cols=ui->lineEdit_2->text().toInt();
        }

      QStandardItemModel* model=new QStandardItemModel(arg1.toInt(),Cols);
            ui->tableView->setModel(model);
    }
}


void MainWindow::on_lineEdit_2_textEdited(const QString &arg1)
{
    if(arg1.toInt())
    {
        int Rows=1;
        if(ui->lineEdit->text().toInt())
        {
            Rows=ui->lineEdit->text().toInt();
        }

       QStandardItemModel* model=new QStandardItemModel(Rows,arg1.toInt());
            ui->tableView->setModel(model);
    }
}


// void MainWindow::on_pushButton_clicked()
// {
//     QString filename("D:/к лабам/MyTables/Table_APL_1.xlsx");
//     QAxObject* excel=new QAxObject("Excel.Application",this);
//     QAxObject* workbooks = excel->querySubObject("Workbooks"); // рабочая книга Bb
//     QAxObject* workbook = workbooks->querySubObject("Open(const QString&)", filename);
//     excel->dynamicCall("SetVisible(bool)",false); // видимость документа

//     QAxObject *worksheet = workbook->querySubObject("WorkSheets(int)",1);//Ss

//     //получаем кол-во используемых строк и столбцов
//     QAxObject * usedrange = worksheet->querySubObject("UsedRange");//Rr
//     QAxObject *rows = usedrange->querySubObject("Rows");
//     QAxObject *columns = usedrange->querySubObject("Columns");

//     int intRowStart = usedrange->property("Row").toInt();
//     int intColStart = usedrange->property("Column").toInt();
//     int intCols = columns->property("Count").toInt();
//     int intRows = rows->property("Count").toInt();

//     QStandardItemModel* model=new QStandardItemModel(intRows,intCols);


//     for (int row=0; row<intRows; row++)
//     {
//         for(int col=0; col<intCols; col++)
//         {
//             QAxObject* cell = worksheet->querySubObject("Cells(int,int)", row+1, col+1);
//             QVariant value = cell->dynamicCall("Value()");
//             model->setItem(row,col, new QStandardItem(value.toString()));
//         }
//     }
//    ui->tableView->setModel(model);
//     //workbook->setProperty("Saved", "True");
//     workbook->dynamicCall("Close");
//     excel->dynamicCall("Quit()");

// }
void MainWindow::on_pushButton_clicked()
{
    QXlsx::Document xlsx;
    xlsx.write(1,1, "Goodbye Qt!"); // write "Hello Qt!" to cell(A,1). it's shared string.
    xlsx.saveAs("Test.xlsx"); // save the document as 'Test.xlsx'
     int row = 1; int col = 1;
   // Document xlsxR("turd.xlsx");
     Document xlsxR("Table_APL_1.xlsx");

    if (xlsxR.load()) // load excel file
    {
        Cell* cell = xlsxR.cellAt(row, col);        // get cell pointer.
        while(cell!=nullptr)
        {
            cell=xlsxR.cellAt(++row,1);
        }
        row--;
        cell=xlsxR.cellAt(1,1);

        while(cell!=nullptr)
        {
            cell=xlsxR.cellAt(1,++col);
        }
        col--;
        //QStandardItemModel* model=new QStandardItemModel(row,col);
        model=new QStandardItemModel(row,col);
        ui->tableView->setModel(model);
        for(int i=0; i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                cell=xlsxR.cellAt(i+1,j+1);
                QVariant var = cell->readValue(); // read cell value (number(double), QDateTime, QString ...)
                model->setItem(i,j, new QStandardItem(var.toString()));
            }
        }
    }


}


void MainWindow::on_pushButton_2_clicked()
{
    QXlsx::Document xlsx;
    int row,col;
    row=ui->tableView->model()->rowCount();
    col=ui->tableView->model()->columnCount();
    for(int i=0; i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            QString temp;
            QModelIndex index = model->index(i,j,QModelIndex());
            temp = model->data(index,0).toString();
            xlsx.write(i+1,j+1, temp);
        }
    }
    xlsx.saveAs("Test.xlsx");
}

