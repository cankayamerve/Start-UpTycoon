#include "game.h"
#include "ui_game.h"

Game::Game(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::Game),
    currentUser(LoginScreen::username) // Initialize the user member variable
{
    ui->setupUi(this);
    setFixedSize(1200, 700);
    setWindowTitle("Start-up Tycoon");
    ui->namelabelkemal->setText(" "+currentUser.getName());
    ui->namelabelkemal->setAlignment(Qt::AlignCenter);
    name={"Andac","Arya","Armagan","Arin","Beyhan","Bilge","Deniz","Derya","Derin","Ekin","Esen","Hazar","Ilkay","Kayra","Goksun","Mutlu","Oflaz","Okyanus","Olgu","Pamir","Ruzgar","Nurhan","Renan","Sonat","Seyhan","Tamay","Tansel","Toprak","Sezgi","Umut","Yuksel","Zeren"};
    surname={"Ileri","Albay","Yildiz","Cankaya","Yilmaz","Kaya","Demir","Ozturk","Arslan","Celik","Tas","Koc","Sahin","Can","Kocaman","Dogan","Gunes","Simsek","Aslan","Tekin","Yildirim","Yavuz","Cetin","Aksoy","Alp","Demirci","Sarac","Caliskan","Dogru","Arikan","Yaman","Kilic","Ay","Sevinc","Kurt"};

    for (int i = 0; i < 31; i++) {
        img[i] = QString(":/emp/empImg/emp%1.jpeg").arg(i + 1);
    }


    ui->yearmoneylabel->setText(" <html><body><p><b> YEAR:</b> " + QString::number(currentUser.getRound()) +" <br><b> MONEY:</b> " + QString::number(currentUser.getMoney()) + "</p></body></html>");
    ui->yearmoneylabel->setStyleSheet("border-radius:10px; border-image: url(:/gamescreen/gamescreenimg/turuncu.png); color: #7a4933; font-size: 12px;");

    //Demonstrating random developer images in each label
    ui->label->setStyleSheet("border-image: url(" + getRandomEmpImage() + "); border-radius: 70px;");
    ui->label_2->setStyleSheet("border-image: url(" + getRandomEmpImage() + ");border-radius: 70px;");
    ui->label_3->setStyleSheet("border-image: url(" + getRandomEmpImage() + ");border-radius: 70px;");
    ui->label_4->setStyleSheet("border-image: url(" + getRandomEmpImage() + ");border-radius: 70px;");
    ui->label_5->setStyleSheet("border-image: url(" + getRandomEmpImage() + ");border-radius: 70px;");


    buyProjectButtonIsCLicked=false;
    buyDeveloperButtonIsCLicked=false;

    selectedProjectName=""; //when user select project, we hold its name

    projectNameCount=0; //provides different project name

    QColor color("#7a4933");

    //Each year we generate new project and add our project array
    for(int i=0;i<3;i++){
        Project pr ("Project_"+QString::number(projectNameCount++),getRandomSpeciality(),10000);
        projectArray[i]=pr;
        ui -> buyprojectwidget->addItem(projectArray[i].getName()+" ("+specialityEnumToString(projectArray[i].getSpeciality())+") Cost: "+QString::number(projectArray[i].getCost()));
        ui->buyprojectwidget -> item(i)->setForeground(color);
    }


    for(int i=0;i<5;i++){
        developerArray[i]=generateRandomDeveloper();
    }

    ui->namelabelkemal->setStyleSheet("border-radius:10px; border-image: url(:/gamescreen/gamescreenimg/turuncu.png); color: #6c402d; font-size: 14px;");
    ui->dev1label->setStyleSheet("border-image:url(:/gamescreen/gamescreenimg/devlabelbackground.jpeg); color: #a66948; font-weight: bold; font-size: 11px;");
    ui->dev2label->setStyleSheet("border-image:url(:/gamescreen/gamescreenimg/devlabelbackground.jpeg); color: #a66948; font-weight: bold; font-size: 11px;");
    ui->dev3label->setStyleSheet("border-image:url(:/gamescreen/gamescreenimg/devlabelbackground.jpeg); color: #a66948; font-weight: bold; font-size: 11px;");
    ui->dev4label->setStyleSheet("border-image:url(:/gamescreen/gamescreenimg/devlabelbackground.jpeg); color: #a66948; font-weight: bold; font-size: 11px;");
    ui->dev5label->setStyleSheet("border-image:url(:/gamescreen/gamescreenimg/devlabelbackground.jpeg); color: #a66948; font-weight: bold; font-size: 11px;");
    ui->selectedDeveloperLabel->setStyleSheet("border-radius: 8px; border-image: url(:/gamescreen/gamescreenimg/morlabel.png); color: #d8d7d8; font-weight: bold; font-size: 14px;");
    ui->selectedDeveloperLabel->setAlignment(Qt::AlignCenter);
    ui->selectedProjectLabel->setStyleSheet("border-radius: 8px; border-image: url(:/gamescreen/gamescreenimg/morlabel.png); color: #d8d7d8; font-weight: bold; font-size: 14px;");
    ui->selectedProjectLabel->setAlignment(Qt::AlignCenter);

    //Send informations to label
    ui->dev1label -> setText("Name: "+developerArray[0].getName()+"\nSpeciality: "+specialityEnumToString( developerArray[0].getSpeciality())+"\nSalary: "+QString::number( developerArray[0].getSalary()));
    ui->dev2label -> setText("Name: "+developerArray[1].getName()+"\nSpeciality: "+specialityEnumToString( developerArray[1].getSpeciality())+"\nSalary: "+QString::number( developerArray[1].getSalary()));
    ui->dev3label -> setText("Name: "+developerArray[2].getName()+"\nSpeciality: "+specialityEnumToString( developerArray[2].getSpeciality())+"\nSalary: "+QString::number( developerArray[2].getSalary()));
    ui->dev4label -> setText("Name: "+developerArray[3].getName()+"\nSpeciality: "+specialityEnumToString( developerArray[3].getSpeciality())+"\nSalary: "+QString::number( developerArray[3].getSalary()));
    ui->dev5label -> setText("Name: "+developerArray[4].getName()+"\nSpeciality: "+specialityEnumToString( developerArray[4].getSpeciality())+"\nSalary: "+QString::number( developerArray[4].getSalary()));


}

Game::~Game()
{
    delete ui;
}

QString Game::getRandomEmpImage() {
    int randomIndex = generateRandomNumber();
    return img[randomIndex];
}

int Game:: generateRandomNumber() {
    int randomNumber;
    do {
        randomNumber = std::rand() % 31;
    } while (std::find(intVector.begin(), intVector.end(), randomNumber) != intVector.end());

    intVector.push_back(randomNumber);
    return randomNumber;
}

void Game::on_gamebackbutton_clicked()
{

    readUserDataFromFile();//if user wanna back, we read name and round informations from txt
    printLeastThreeRounds();//we look our txt and select top 3 user
    this->hide();
    FirstScreen fs ;
    fs.setModal(true);
    fs.exec();

}


void Game::on_gamenextbutton_clicked()
{
    double currentMoney=currentUser.getMoney();
    income();
    salaryCalculator();
    double currentMoney2=currentUser.getMoney();
    //if your income is positive text is green
    if(currentMoney2-currentMoney<=0){
        ui->incomeLabel->setStyleSheet("border-radius:10px; border-image: url(:/gamescreen/gamescreenimg/turuncu.png); color: #aa0000; font-size: 12px;");
    }
    else{
        ui->incomeLabel->setStyleSheet("border-radius:10px; border-image: url(:/gamescreen/gamescreenimg/turuncu.png); color: #008d00; font-size: 12px;");
    }
    ui->incomeLabel->setText("<html><body><p><b> Net Profit:</b> "+QString::number(currentMoney2-currentMoney));
    if(static_cast<int>(currentUser.getMoney())<=0){
        ui->yearmoneylabel->setText(" <html><body><p><b> YEAR:</b> " + QString::number(currentUser.getRound()) +" <br><b> MONEY:</b> " + QString::number(currentUser.getMoney()) + "</p></body></html>");
        disablingButtons();
        this->hide();
        resultscreen res;
        res.losingBackground();
        res.setModal(true);
        res.exec();
    }
    else if(currentUser.getMoney()>=1000000){
        ui->yearmoneylabel->setText(" <html><body><p><b> YEAR:</b> " + QString::number(currentUser.getRound()) +" <br><b> MONEY:</b> " + QString::number(currentUser.getMoney()) + "</p></body></html>");
        disablingButtons();
        saveUserDataToFile();
        readUserDataFromFile();
        printLeastThreeRounds();
        this->hide();
        resultscreen res;
        res.winningBackground();
        res.setModal(true);
        res.exec();

    }
    else{
        updateGame();
    }
}

void Game::disablingButtons(){
    ui->buydeveloper1button->setEnabled(false);
    ui->buydeveloper2button->setEnabled(false);
    ui->buydeveloper3button->setEnabled(false);
    ui->buydeveloper4button->setEnabled(false);
    ui->buydeveloper5button->setEnabled(false);
    ui->buynowbutton->setEnabled(false);
    ui->deletedeveloperbutton->setEnabled(false);
    ui->deleteprojebutton->setEnabled(false);
    ui->matchingButton->setEnabled(false);
    ui->gamenextbutton->setEnabled(false);
}
void Game::on_deleteprojebutton_clicked()
{
    if(!ui -> selectedProjectLabel -> text().isEmpty()){
        QString projectName=ui -> selectedProjectLabel -> text();
        for(int i=0;i<currentUser.getProjects().size();i++){
            if(currentUser.getProjects()[i].getName()==projectName){
                //we control widget in reverse order to delete developer which their projects are already deleted
                for (int j = ui->developerListWidget->count() - 1; j >= 0; j--) {
                    QListWidgetItem *developerItem = ui->developerListWidget->item(j);
                    int index= developerItem->text().indexOf(" ");
                    QString findItem=developerItem->text().mid(0,index);
                    for(int k=0;k<currentUser.getProjects()[i].getDevelopersinProject().size();k++){
                        if(currentUser.getProjects()[i].getDevelopersinProject()[k].getName()==findItem){
                        ui->developerListWidget->takeItem(ui->developerListWidget->row(ui->developerListWidget->item(j)));
                        currentUser.getProjects()[i].deleteDeveloperinProject(currentUser.getProjects()[i].getDevelopersinProject()[k]);
                        }
                    }
                }
            }
        }
        currentUser.deleteProject(currentUser.getProjectWithName(projectName));
        ui->projectListWidget->takeItem(ui->projectListWidget->row(selectedWidgetItemProject));
        ui -> selectedProjectLabel ->clear();
    }

}

//developer cant be deleted if he or she work in any project
void Game::on_deletedeveloperbutton_clicked()
{
    if(!ui -> selectedDeveloperLabel -> text().isEmpty()){
        QString name=ui -> selectedDeveloperLabel -> text();
        for (int i=0;i<currentUser.getDevelopers().size();i++) {
            if (currentUser.getDevelopers()[i].getName()== name) {
                currentUser.deleteDeveloper(currentUser.getDeveloperWithName(name));
                ui->developerListWidget->takeItem(ui->developerListWidget->row(selectedWidgetItemDeveloper));
                ui-> selectedDeveloperLabel -> clear();
            }
        }
    }
}


void Game::changeWidgetColor(){
    QColor color("#6a2543");
    for(int i=0;i<ui->projectListWidget->count();i++){
        ui->projectListWidget -> item(i)->setForeground(color);
    }
    for(int i=0;i<ui->developerListWidget->count();i++){
        ui->developerListWidget -> item(i)->setForeground(color);
    }
}

//add selected developer to user's developer vector and set new developer to label
void Game::on_buydeveloper1button_clicked()
{

    if(currentUser.getMoney()>=developerArray[0].getSalary()){
        buyDeveloperButtonIsCLicked=true;
        currentUser.addDeveloper(developerArray[0]);
        currentUser.setMoney(currentUser.getMoney()-developerArray[0].getSalary());
        ui->developerListWidget->addItem(developerArray[0].getName()+" " +specialityEnumToString(developerArray[0].getSpeciality()));
        changeWidgetColor();
        developerArray[0]=generateRandomDeveloper();
        ui->yearmoneylabel->setText(" <html><body><p><b> YEAR:</b> " + QString::number(currentUser.getRound()) +" <br><b> MONEY:</b> " + QString::number(currentUser.getMoney()) + "</p></body></html>");
        ui->dev1label -> setText("Name: "+developerArray[0].getName()+"\nSpeciality: "+specialityEnumToString( developerArray[0].getSpeciality())+"\nSalary: "+QString::number( developerArray[0].getSalary()));
        ui->label->setStyleSheet("border-image: url(" + getRandomEmpImage() + "); border-radius: 70px;");
    }

}


void Game::on_buydeveloper2button_clicked()
{
    if(currentUser.getMoney()>=developerArray[1].getSalary()){
        buyDeveloperButtonIsCLicked=true;
        currentUser.addDeveloper(developerArray[1]);
        currentUser.setMoney(currentUser.getMoney()-developerArray[1].getSalary());
        ui->developerListWidget->addItem(developerArray[1].getName()+" " +specialityEnumToString(developerArray[1].getSpeciality()));
        changeWidgetColor();
        developerArray[1]=generateRandomDeveloper();
        ui->yearmoneylabel->setText(" <html><body><p><b> YEAR:</b> " + QString::number(currentUser.getRound()) +" <br><b> MONEY:</b> " + QString::number(currentUser.getMoney()) + "</p></body></html>");
        ui->dev2label -> setText("Name: "+developerArray[1].getName()+"\nSpeciality: "+specialityEnumToString( developerArray[1].getSpeciality())+"\nSalary: "+QString::number( developerArray[1].getSalary()));
        ui->label_2->setStyleSheet("border-image: url(" + getRandomEmpImage() + "); border-radius: 70px;");
    }
}


void Game::on_buydeveloper3button_clicked()
{
    if(currentUser.getMoney()>=developerArray[2].getSalary()){
        buyDeveloperButtonIsCLicked=true;
        currentUser.addDeveloper(developerArray[2]);
        currentUser.setMoney(currentUser.getMoney()-developerArray[2].getSalary());
        ui->developerListWidget->addItem(developerArray[2].getName()+" " +specialityEnumToString(developerArray[2].getSpeciality()));
        changeWidgetColor();
        developerArray[2]=generateRandomDeveloper();
        ui->yearmoneylabel->setText(" <html><body><p><b> YEAR:</b> " + QString::number(currentUser.getRound()) +" <br><b> MONEY:</b> " + QString::number(currentUser.getMoney()) + "</p></body></html>");
        ui->dev3label -> setText("Name: "+developerArray[2].getName()+"\nSpeciality: "+specialityEnumToString( developerArray[2].getSpeciality())+"\nSalary: "+QString::number( developerArray[2].getSalary()));
        ui->label_3->setStyleSheet("border-image: url(" + getRandomEmpImage() + "); border-radius: 70px;");
    }
}


void Game::on_buydeveloper4button_clicked()
{
    if(currentUser.getMoney()>=developerArray[3].getSalary()){
        buyDeveloperButtonIsCLicked=true;
        currentUser.addDeveloper(developerArray[3]);
        currentUser.setMoney(currentUser.getMoney()-developerArray[3].getSalary());
        ui->developerListWidget->addItem(developerArray[3].getName()+" " +specialityEnumToString(developerArray[3].getSpeciality()));
        changeWidgetColor();
        developerArray[3]=generateRandomDeveloper();
        ui->yearmoneylabel->setText(" <html><body><p><b> YEAR:</b> " + QString::number(currentUser.getRound()) +" <br><b> MONEY:</b> " + QString::number(currentUser.getMoney()) + "</p></body></html>");
        ui->dev4label -> setText("Name: "+developerArray[3].getName()+"\nSpeciality: "+specialityEnumToString( developerArray[3].getSpeciality())+"\nSalary: "+QString::number( developerArray[3].getSalary()));
        ui->label_4 -> setStyleSheet("border-image: url(" + getRandomEmpImage() + "); border-radius: 70px;");
    }
}


void Game::on_buydeveloper5button_clicked()
{
    if(currentUser.getMoney()>=developerArray[4].getSalary()){
        buyDeveloperButtonIsCLicked=true;
        currentUser.addDeveloper(developerArray[4]);
        currentUser.setMoney(currentUser.getMoney()-developerArray[4].getSalary());
        ui->developerListWidget->addItem(developerArray[4].getName()+" " +specialityEnumToString(developerArray[4].getSpeciality()));
        changeWidgetColor();
        developerArray[4]=generateRandomDeveloper();
        ui->yearmoneylabel->setText(" <html><body><p><b> YEAR:</b> " + QString::number(currentUser.getRound()) +" <br><b> MONEY:</b> " + QString::number(currentUser.getMoney()) + "</p></body></html>");
        ui->dev5label -> setText("Name: "+developerArray[4].getName()+"\nSpeciality: "+specialityEnumToString( developerArray[4].getSpeciality())+"\nSalary: "+QString::number( developerArray[4].getSalary()));
        ui->label_5->setStyleSheet("border-image: url(" + getRandomEmpImage() + "); border-radius: 70px;");
    }
}


Developer Game::generateRandomDeveloper(){

    Speciality s1 = static_cast<Speciality>(rand() % 6);  // Random speciality
    Speciality s2 = static_cast<Speciality>(rand() % 6);  // Random secret speciality
    Developer dev(s1,s2,generateRandomFullname(),generateRandomMoney(),0);
    return dev;
}

//generate full name and control that name is exist or not
QString Game::generateRandomFullname(){
    QString createName=name[rand() % name.size()]+"_"+surname[rand() % surname.size()];
    auto iter = std::find(namesOfEmployees.begin(), namesOfEmployees.end(), createName);
    while(iter != namesOfEmployees.end()){
        createName=name[rand() % name.size()]+"_"+surname[rand() % surname.size()];
        iter = std::find(namesOfEmployees.begin(), namesOfEmployees.end(), createName);
    }
    namesOfEmployees.push_back(createName);
    return createName;
}


void Game::on_buyprojectwidget_itemClicked(QListWidgetItem *item) {
    selectedProjectName = item->text();

}

void Game::on_buynowbutton_clicked() {
    if (!selectedProjectName.isEmpty()&&!buyProjectButtonIsCLicked) {
        int index= selectedProjectName.indexOf(" ");
        QString findProject=selectedProjectName.mid(0,index);
        for(int i=0;i<3;i++){
            if(projectArray[i].getName()==findProject && currentUser.getMoney()>=projectArray[i].getCost()){
                currentUser.addProject(projectArray[i]);
                ui->projectListWidget->addItem(selectedProjectName);
                changeWidgetColor();
                currentUser.setMoney(currentUser.getMoney()-projectArray[i].getCost());
                ui->yearmoneylabel->setText(" <html><body><p><b> YEAR:</b> " + QString::number(currentUser.getRound()) +" <br><b> MONEY:</b> " + QString::number(currentUser.getMoney()) + "</p></body></html>");
                buyProjectButtonIsCLicked=true;
            }
        }
    }

}
int Game::generateRandomMoney() {
   return (std::rand() % 30001) + 20000; // generate random number between 20000 and 50000
}

Speciality Game::getRandomSpeciality() {
    return static_cast<Speciality>(QRandomGenerator::global()->bounded(0, Num_Specialities));
}

QString Game::specialityEnumToString(Speciality spc) {
    switch (spc) {
    case Speciality::Game_spc:
        return "Game Speciality";
    case Speciality::Front_end:
        return "Front-end";
    case Speciality::Back_end:
        return "Back-end";
    case Speciality::Data_sci:
        return "Data Science";
    case Speciality::Cyber_sec:
        return "Cyber Security";
    case Speciality::Ai:
        return "AI";
    default:
        return "Unknown";
    }
}

void Game::on_projectListWidget_itemClicked(QListWidgetItem *item)
{
    selectedWidgetItemProject=item;
    int index= item->text().indexOf(" ");
    ui-> selectedProjectLabel->setText(item->text().mid(0,index));
}


void Game::on_developerListWidget_itemClicked(QListWidgetItem *item)
{
    selectedWidgetItemDeveloper=item;
    int index= item->text().indexOf(" ");
    ui-> selectedDeveloperLabel->setText(item->text().mid(0,index));
}


//one developer can work only one project
void Game::on_matchingButton_clicked()
{
    if(!ui -> selectedProjectLabel -> text().isEmpty() && !ui -> selectedDeveloperLabel -> text().isEmpty() ){
        if(!currentUser.getDeveloperWithName(ui -> selectedDeveloperLabel -> text()).getName().isEmpty()){
            for(int i=0;i<currentUser.getProjects().size();i++){
                if(currentUser.getProjects()[i].getName()==ui->selectedProjectLabel -> text()){
                    currentUser.getProjects()[i].addDeveloperinProject(currentUser.getDeveloperWithName(ui -> selectedDeveloperLabel -> text()));
                    currentUser.deleteDeveloper(currentUser.getDeveloperWithName(ui -> selectedDeveloperLabel -> text()));
                    ui -> selectedProjectLabel -> setText("");
                    ui-> selectedDeveloperLabel -> setText("");
                }
            }
        }
    }

}

void Game::salaryCalculator(){
    //set salary of all  developer (even they work in project or not)
    for(int i= 0;i<currentUser.getProjects().size();i++){
        currentUser.setMoney(currentUser.getMoney()-currentUser.getProjects()[i].managerCost());
        for(int j= 0;j<currentUser.getProjects()[i].getDevelopersinProject().size();j++){
            if(currentUser.getProjects()[i].getDevelopersinProject()[j].getYear()!=0){
                currentUser.setMoney(currentUser.getMoney()-currentUser.getProjects()[i].getDevelopersinProject()[j].getSalary());

            }
            else{
                currentUser.getProjects()[i].getDevelopersinProject()[j].setYear(1);
            }
        }
    }

    for(int i= 0;i<currentUser.getDevelopers().size();i++){
        if(currentUser.getDevelopers()[i].getYear()!=0){
            currentUser.setMoney(currentUser.getMoney()-currentUser.getDevelopers()[i].getSalary());
        }
        else{
            currentUser.getDevelopers()[i].setYear(1);
        }
    }
    //each year we get  tax this user
    if(currentUser.getRound()!=0 && currentUser.getMoney()>0){
        if(!buyProjectButtonIsCLicked && !buyDeveloperButtonIsCLicked){
            currentUser.setMoney(currentUser.getMoney()-currentUser.getMoney()/1.5);
        }
        else{
            if(currentUser.getRound()%4==0){
                currentUser.setMoney(currentUser.getMoney()-currentUser.getMoney()/1.4);
            }
            else{
                currentUser.setMoney(currentUser.getMoney()-currentUser.getMoney()/2.5);
            }
        }
    }
}

//we define their income depends on their speciality
void Game::income(){
    int incomeMoney;
    for(int i= 0;i<currentUser.getProjects().size();i++){
        QRandomGenerator random(QRandomGenerator::securelySeeded());
        incomeMoney=currentUser.getProjects()[i].managerCost()*random.generateDouble();
        currentUser.setMoney(currentUser.getMoney()+incomeMoney);
        for(int j= 0;j<currentUser.getProjects()[i].getDevelopersinProject().size();j++){
            if(currentUser.getProjects()[i].getDevelopersinProject()[j].getSpeciality()==currentUser.getProjects()[i].getSpeciality()){
                incomeMoney=(std::rand() % 10000) + currentUser.getProjects()[i].getDevelopersinProject()[j].getSalary()+10000;
                currentUser.setMoney(currentUser.getMoney()+incomeMoney);
            }
            else if(currentUser.getProjects()[i].getDevelopersinProject()[j].getSecretSpeciality()==currentUser.getProjects()[i].getSpeciality()){
                incomeMoney=(std::rand() % 15000) + currentUser.getProjects()[i].getDevelopersinProject()[j].getSalary()+10000;
                currentUser.setMoney(currentUser.getMoney()+incomeMoney);
            }
            else{
                incomeMoney=(std::rand() % 10000) + currentUser.getProjects()[i].getDevelopersinProject()[j].getSalary()-10000;
                currentUser.setMoney(currentUser.getMoney()+incomeMoney);
            }
        }
    }
}

//we display game screen when user advance to next year
void Game::updateGame(){

    intVector.clear();

    for(int i=0;i<5;i++){
        developerArray[i]=generateRandomDeveloper();
    }

    ui->dev1label -> setText("Name: "+developerArray[0].getName()+"\nSpeciality: "+specialityEnumToString( developerArray[0].getSpeciality())+"\nSalary: "+QString::number( developerArray[0].getSalary()));
    ui->dev2label -> setText("Name: "+developerArray[1].getName()+"\nSpeciality: "+specialityEnumToString( developerArray[1].getSpeciality())+"\nSalary: "+QString::number( developerArray[1].getSalary()));
    ui->dev3label -> setText("Name: "+developerArray[2].getName()+"\nSpeciality: "+specialityEnumToString( developerArray[2].getSpeciality())+"\nSalary: "+QString::number( developerArray[2].getSalary()));
    ui->dev4label -> setText("Name: "+developerArray[3].getName()+"\nSpeciality: "+specialityEnumToString( developerArray[3].getSpeciality())+"\nSalary: "+QString::number( developerArray[3].getSalary()));
    ui->dev5label -> setText("Name: "+developerArray[4].getName()+"\nSpeciality: "+specialityEnumToString( developerArray[4].getSpeciality())+"\nSalary: "+QString::number( developerArray[4].getSalary()));

    ui->yearmoneylabel->setText(" <html><body><p><b> YEAR:</b> " + QString::number(currentUser.getRound()) +" <br><b> MONEY:</b> " + QString::number(currentUser.getMoney()) + "</p></body></html>");
    ui->label->setStyleSheet("border-image: url(" + getRandomEmpImage() + "); border-radius: 70px;");
    ui->label_2->setStyleSheet("border-image: url(" + getRandomEmpImage() + ");border-radius: 70px;");
    ui->label_3->setStyleSheet("border-image: url(" + getRandomEmpImage() + ");border-radius: 70px;");
    ui->label_4->setStyleSheet("border-image: url(" + getRandomEmpImage() + ");border-radius: 70px;");
    ui->label_5->setStyleSheet("border-image: url(" + getRandomEmpImage() + ");border-radius: 70px;");

    currentUser.setRound(currentUser.getRound()+1);
    ui->yearmoneylabel->setText(" <html><body><p><b> YEAR:</b> " + QString::number(currentUser.getRound()) +" <br><b> MONEY:</b> " + QString::number(currentUser.getMoney()) + "</p></body></html>");

   //we obtain user can buy a project again
    buyProjectButtonIsCLicked=false;
    buyDeveloperButtonIsCLicked=false;
    selectedProjectName="";


    ui->buyprojectwidget-> clear();

    //update project count
    QColor color("#7a4933");
    for(int i=0;i<3;i++){
        Project pr ("Project_"+QString::number(projectNameCount++),getRandomSpeciality(),10000);
        projectArray[i]=pr;
        ui -> buyprojectwidget->addItem(projectArray[i].getName()+" ("+specialityEnumToString(projectArray[i].getSpeciality())+") Cost: "+QString::number(projectArray[i].getCost()));
        ui->buyprojectwidget -> item(i)->setForeground(color);
    }

}


void Game::saveUserDataToFile()
{
    // Determine the location for storing user data (use the application's current working directory)
    QString projectDir = QCoreApplication::applicationDirPath();

    // Construct the file path for storing user data in the project folder
    QString filePath = projectDir + "/userdata.txt";

    // Create a QFile object with the specified file path
    QFile file(filePath);

    // Open the file in write mode (create if not exist, append if exists)
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {

        QTextStream out(&file);
        out << currentUser.getName() << "/" << currentUser.getRound();
        out << "\n";  // Add a newline to separate entries
        file.close();

    } else {
        // Handle the case where the file couldn't be opened
        qDebug() << "Error opening file for writing:" << file.errorString();
    }
}
void Game::readUserDataFromFile() {


    QString projectDir = QCoreApplication::applicationDirPath();

    QFile file(projectDir + "/userdata.txt");

    // Open the file in read-only mode
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // Create a QTextStream to read from the file
        QTextStream in(&file);

        // Read the file line by line
        while (!in.atEnd()) {
            // Read a line from the file
            QString line = in.readLine();
            qDebug()<< "line in read method "<< line;
            // Split the line into parts based on the "/" separator
            int index=line.indexOf("/");
            QString name=line.mid(0,index);
            QString round=line.mid(line.length()-1);
            names.push_back(name);
            rounds.push_back(round.toInt());
        }
        file.close();
    } else {
        // Handle the case where the file couldn't be opened
        qDebug() << "Error opening file for reading:" << file.errorString();
    }
}

void Game::printLeastThreeRounds() {
    if(rounds.size()>=3){
        int round1=rounds.at(0);
        int round2=rounds.at(1);
        int round3=rounds.at(2);

        QString name1;
        QString name2;
        QString name3;

        for(int i=0;i<rounds.size();i++){
            if(rounds[i]<=round1){
                round1= rounds[i];
                name1= names[i];

            }
            else if(rounds[i]<=round2){
                round2= rounds[i];
                name2= names[i];

            }
            else if(rounds[i]<=round3){
                round3= rounds[i];
                name3= names[i];

            }

        }

        ScoreBoard::labelsString[0]=("Name: "+ name1+ "\nRound: "+QString::number(round1));
        ScoreBoard::labelsString[1]=("Name: "+ name2+ "\nRound: "+QString::number(round2));
        ScoreBoard::labelsString[2]=("Name: "+ name3+ "\nRound: "+QString::number(round3));


    }



}
