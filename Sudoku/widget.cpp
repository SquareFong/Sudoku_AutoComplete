#include "widget.h"
#include "ui_widget.h"
#include "shuDu.h"

#include<QDialog>
#include<QMessageBox>
#include<QString>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setFixedSize(468,520);
    ui->tableView->setGeometry(8,8,452,452);
    ui->pushButton->setGeometry(8,465,80,45);
    ui->pushButton_2->setGeometry(192,465,80,45);
    ui->pushButton_3->setGeometry(380,465,80,45);


    ui->tableView->verticalHeader()->hide();
    ui->tableView->horizontalHeader()->hide();

    model = new QStandardItemModel();
    model->setColumnCount(9);
    char n('1');
    for(int i(0); i<9; ++i,++n){
        string s;
        s += n;
        model->setHeaderData(i,Qt::Horizontal,QString::fromStdString(s));
    }
    ui->tableView->setModel(model);
    for(int i(0); i<9; ++i)
        ui->tableView->setColumnWidth(i,50);
    for(int i(0); i<9; ++i){
        for(int j(0);j<9;++j){
            model->setItem(i,j, new QStandardItem(QString("")));
            model->item(i,j)->setTextAlignment(Qt::AlignCenter);
            model->item(i,j)->setFont(QFont("Times", 24, QFont::Black));
            model->item(i,j)->setForeground(QBrush(QColor(128,128,128)));
        }
        ui->tableView->setRowHeight(i,50);
    }

    ui->tableView->setEditTriggers(QAbstractItemView::AllEditTriggers);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    shuDu s;
    for(int i(0); i<9; ++i){
        for(int j(0);j<9;++j){
            QString number=model->item(i,j)->text();
            if(number.length()){
                int n = number.toInt();
                if(n > 0 && n <= 9){
                    s.setNumber(i,j,n);
                    model->item(i,j)->setForeground(QBrush(QColor(0,0,0)));
                }
                else {
                    QMessageBox::information(this,"Erro","You can only input numbers between 1 and 9\n Please Fix it and try again");
                    return;
//                    QDialog d(this);
//                    d.resize(160,90);
//                    d.setWindowTitle("In Put Erro, Please Fix it and try again");
//                    d.
//                    d.exec();
                }
            }
        }
    }
    if(s.Start()){
        for(int i(0); i<9; ++i){
            for(int j(0);j<9;++j){
                char n=(s.getNumber(i,j)+'0');
                string number;
                number+=n;
                model->item(i,j)->setText(QString::fromStdString(number));
            }
        }
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }
    else
        QMessageBox::information(this,"Message","No result");
}

void Widget::on_pushButton_2_clicked()
{
    for(int i(0); i<9; ++i){
        for(int j(0);j<9;++j){
            string number;
            model->item(i,j)->setText(QString::fromStdString(number));
            model->item(i,j)->setForeground(QBrush(QColor(128,128,128)));
        }
    }
    ui->tableView->setEditTriggers(QAbstractItemView::AllEditTriggers);
}

void Widget::on_pushButton_3_clicked()
{
    QMessageBox::information(this,"Help"," This is a Sudoku auto-run programme\n Please input number and click \'run\'\n Each time it run successfully, please click \'clear\'\n Otherwise, you can't input\n Have fun!");
}
