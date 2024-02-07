#include "developer.h"

Developer::Developer(Speciality s1, Speciality s2, QString s, int money, int year)
    : Employee(s, money, year), d_speciality(s1), d_secretSpeciality(s2) {

}
Developer::Developer(){
}
Speciality Developer::getSpeciality() {
    return d_speciality;
};
Speciality Developer::getSecretSpeciality(){
    return d_secretSpeciality;
}

