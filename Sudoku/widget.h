#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QStandardItemModel>
#include<string>
using namespace std;

namespace Ui {
class Widget;
}
//test comment
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Widget *ui;
    QStandardItemModel *model;
};

#endif // WIDGET_H
