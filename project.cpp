#include "project.h"

int Project::count=0;

Project::Project(QString name ,Speciality speciality ,int cost) {
    this->name=name;
    this->speciality=speciality;
    this->cost=cost;
    id = count;
    m = Manager(speciality, QString("Manager_").append(QString::number(count)), 30000, 0);
    count++;
}

Project::Project(){

}

void Project::addDeveloperinProject(Developer d){
    developersinProject.push_back(d);
}

void Project::deleteDeveloperinProject(Developer d){
    auto it = std::find(developersinProject.begin(), developersinProject.end(), d);
    if (it != developersinProject.end()) {
       developersinProject.erase(it);
    };
}

bool operator==(const Project& other, const Project& other2) {
    return other.id == other2.id;
}
QString Project::getName(){
    return name;
}
int Project::getCost(){
    return cost;
}

Speciality Project::getSpeciality(){
    return speciality;
}

std::vector<Developer>& Project::getDevelopersinProject() {
    return developersinProject;
}

int Project::managerCost(){
    return m.getSalary();
}
