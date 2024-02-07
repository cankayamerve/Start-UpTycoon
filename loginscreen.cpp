#include "loginscreen.h"
#include "ui_loginscreen.h"

QString LoginScreen::username="";

LoginScreen::LoginScreen(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginScreen)
{

    ui->setupUi(this);
    setFixedSize(1200,700);
    setWindowTitle("Start-up Tycoon");

    connect(ui->usernameLineEdit, &QLineEdit::textEdited, this, &LoginScreen::on_usernameLineEdit_textEdited);

    ui->genderLabel->setStyleSheet("border-image: url(:/image1/img/whitebackground.jpeg); color: rgb(13, 79, 103); font-size: 12pt;");
    ui->genderLabel->setAlignment(Qt::AlignCenter);
    ui->usernameLineEdit->setAlignment(Qt::AlignCenter);
    isClicked=false;
}

LoginScreen::~LoginScreen()
{
    delete ui;
}

void LoginScreen::on_womanButton_clicked()
{
    this->gender=Female;
    ui->genderLabel->setText("Female");
    isClicked=true;
    ui->womanButton->setStyleSheet("border-image: url(':/loginscr/loginscreenimg/selected_female2.png');");
    ui->manButton->setStyleSheet("border-image: url(':/image1/img/male.jpg');");

}
void LoginScreen::on_manButton_clicked()
{
    this->gender=Male;
    ui->genderLabel->setText("Male");
    isClicked=true;
    ui->manButton->setStyleSheet("border-image: url(':/loginscr/loginscreenimg/selected_male2.png');");
    ui->womanButton->setStyleSheet("border-image: url(':/image1/img/female.jpg');");

}

void LoginScreen::on_backButton_clicked()
{
    this->hide();
    FirstScreen firstS;
    firstS.setModal(true);
    firstS.exec();

}

void LoginScreen::on_nextButton_clicked()
{
    //If user doesnt enter space and clicked any gender he or she can plays the game
    if (ui->usernameLineEdit->text().toStdString()!="" && isClicked) {
        this->hide();
        Game g;
        g.setModal(true);
        g.exec();
    }
}


void LoginScreen::on_usernameLineEdit_textEdited(const QString &arg1)
{
    //Prevent username variable has space
    ui->usernameLineEdit->setMaxLength(20);
    QString filteredText = arg1.simplified();
    filteredText.replace(" ", "");
    ui->usernameLineEdit->setText(filteredText);
    username = arg1;
}



