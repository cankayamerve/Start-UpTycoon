#include "scoreboard.h"
#include "ui_scoreboard.h"

#include <QDebug>

QString ScoreBoard::labelsString[3];

ScoreBoard::ScoreBoard(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ScoreBoard)
{

    ui->setupUi(this);
    setFixedSize(1200,700);
    setWindowTitle("Start-up Tycoon");
    ui->firstLabel->setStyleSheet("border-image: url(:/image1/img/whitebackground.jpeg); color: #458b8f; font-size: 20px;");
    ui->firstLabel->setText(labelsString[0]);
    ui->secondLabel->setStyleSheet("border-image: url(:/image1/img/whitebackground.jpeg); color: #458b8f; font-size: 20px;");
    ui->secondLabel->setText(labelsString[1]);
    ui->thirdLabel->setStyleSheet("border-image: url(:/image1/img/whitebackground.jpeg); color: #458b8f; font-size: 20px;");
    ui->thirdLabel->setText(labelsString[2]);

}

ScoreBoard::~ScoreBoard()
{
    delete ui;
}

void ScoreBoard::on_backScoreButton_clicked()
{
    this->hide();
    FirstScreen firstS;
    firstS.setModal(true);
    firstS.exec();
}



