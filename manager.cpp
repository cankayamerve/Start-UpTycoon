#include "manager.h"


Manager::Manager() {

}
Manager::Manager(Speciality s1,QString s, int money, int year)
    : Employee(s, money, year), m_speciality(s1) {
    this->salary=money;
}
int Manager::getSalary(){
    return salary;
}

Speciality Manager::getSpeciality() {
    return m_speciality;
}

