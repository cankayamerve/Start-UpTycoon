#ifndef MANAGER_H
#define MANAGER_H

#include "employee.h"
#include "Speciality.h"
#include <QString>

/**
 * @brief The Manager class represents an employee specializing in management roles.
 *
 * This class is derived from the Employee class and extends its functionality by
 * incorporating additional attributes related to management. Each Manager has a
 * speciality (publicly accessible), and the salary is specified separately. The Manager
 * class allows for the encapsulation of information regarding the specific skills and
 * expertise of an employee in the field of management.
 *
 * Usage example:
 * \code
 *     Speciality managerSpeciality("Project Management");
 *     Manager manager(managerSpeciality, "Ahmet Gül", 90000, 2015);
 *
 *     QString managerName = manager.getName();
 *     Speciality managerSpeciality = manager.getSpeciality();
 *     int managerSalary = manager.getSalary();
 * \endcode
 */
class Manager : public Employee
{
public:
    /**
     * @brief Default constructor for creating an empty Manager object.
     */
    Manager();

    /**
     * @brief Parameterized constructor for creating a Manager object with specified attributes.
     * @param s1 The speciality of the manager.
     * @param name The name of the manager.
     * @param money The salary of the manager.
     * @param year The year of employment for the manager.
     */
    Manager(Speciality s1, QString name, int money, int year);

    /**
     * @brief Getter function for retrieving the salary of the manager.
     * @return The salary of the manager.
     */
    int getSalary();

    /**
     * @brief Getter function for retrieving the speciality of the manager.
     * @return The speciality of the manager.
     */
    Speciality getSpeciality();

private:
    Speciality m_speciality; ///< The speciality of the manager.
    int salary;              ///< The salary of the manager.
};

#endif // MANAGER_H
