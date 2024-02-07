#include "resultscreen.h"
#include "ui_resultscreen.h"

resultscreen::resultscreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::resultscreen)
{
    ui->setupUi(this);
    setFixedSize(1200,700);
    setWindowTitle("Start-up Tycoon");

}

resultscreen::~resultscreen()
{
    delete ui;
}

void resultscreen::on_pushButton_clicked()
{
    FirstScreen f;
    this ->hide();
    f.setModal(true);
    f.exec();
}

void resultscreen::winningBackground(){
    this -> setStyleSheet("border-image: url(:/gameresultimg/resultimg/win_screen.png)");
}
void resultscreen::losingBackground(){
    this -> setStyleSheet("border-image: url(:/gameresultimg/resultimg/lose_screen.png)");
}
