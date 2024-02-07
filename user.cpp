#include "user.h"


User::User(QString name) : name(name), round(0), money(100000) {

}
QString User::getName() const {
    return name;
}
double User::getMoney() {
    return money;
}
void User::setMoney(double newMoney) {
    money = newMoney;
}
int User::getRound() {
    return round;
}
void User::setRound(int newRound) {
    round = newRound;
}
bool operator==(const User& other, const User& other2) {
    return other.getName() == other2.getName();
}
void User::addProject(Project p){
    projects.push_back(p);
}
void User::deleteProject(Project p){
    auto it = std::find(projects.begin(), projects.end(), p);
    if (it != projects.end()) {
        projects.erase(it);
    };
}
void User::addDeveloper(Developer dev1){
    developers.push_back(dev1);
}

void User::deleteDeveloper(Developer dev1){
    auto it = std::find(developers.begin(), developers.end(), dev1);
    if (it != developers.end()) {
        developers.erase(it);
    };
}

Project User::getProjectWithName(QString name){
    for(int i=0;i<projects.size();i++){
        if(projects.at(i).getName()==name){
            return projects.at(i);
        }
    }
    return Project();
}

Developer User::getDeveloperWithName(QString name){
    for(int i=0;i<developers.size();i++){
        if(developers.at(i).getName()==name){
            return developers.at(i);
        }
    }
    return Developer();
}

std::vector<Project>& User::getProjects() {
    return projects;
}

std::vector<Developer>& User::getDevelopers() {
    return developers;
}
