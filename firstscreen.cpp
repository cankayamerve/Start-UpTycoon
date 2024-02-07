#include "firstscreen.h"
#include "ui_firstscreen.h"

FirstScreen::FirstScreen(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FirstScreen)
{
    ui->setupUi(this);
    setFixedSize(1200,700);
    setWindowTitle("Start-up Tycoon");
}

FirstScreen::~FirstScreen()
{
    delete ui;
}

void FirstScreen::on_startButton_clicked()
{
    this->hide();
    LoginScreen login;
    login.setModal(true);
    login.exec();
}


void FirstScreen::on_scoreButton_clicked()
{
    this->hide();
    ScoreBoard score;
    score.setModal(true);
    score.exec();
}

