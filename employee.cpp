#include "employee.h"

int Employee::count=0;

Employee::Employee() {

}

Employee::Employee(QString name, int salary, int year){
    this->name=name;
    this->salary=salary;
    this->year=year;
    id = count;
    count++;
}

QString Employee:: getName(){
    return name;
}
int Employee:: getSalary(){
    return salary;
}

int Employee:: getYear(){
    return year;
}
void Employee:: setYear(int y){
    year=y;
}
bool operator==(const Employee& emp1, const Employee& emp2) {

    return emp1.id == emp2.id;
}
