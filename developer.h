#ifndef DEVELOPER_H
#define DEVELOPER_H

#include "employee.h"
#include "speciality.h"

/**
 * @brief The Developer class represents an employee specializing in development.
 *
 * This class is derived from the Employee class and extends its functionality by
 * incorporating additional attributes related to development. Each Developer has a
 * primary speciality (publicly accessible) and a secret speciality (accessible through
 * designated methods). The Developer class allows for the encapsulation of information
 * regarding the specific skills and expertise of an employee in the field of development.
 *
 * Usage example:
 * \code
 *     Speciality primarySpeciality("C++ Programming");
 *     Speciality secretSpeciality("Algorithm Design");
 *     Developer dev(primarySpeciality, secretSpeciality, "John Doe", 75000, 2018);
 *
 *     QString devName = dev.getName();
 *     Speciality devPrimarySpeciality = dev.getSpeciality();
 *     Speciality devSecretSpeciality = dev.getSecretSpeciality();
 * \endcode
 */
class Developer : public Employee
{
private:
    Speciality d_speciality;         ///< The primary speciality of the developer.
    Speciality d_secretSpeciality;   ///< The secret speciality of the developer.

public:
    /**
     * @brief Parameterized constructor for creating a Developer object with specified attributes.
     * @param s1 The primary speciality of the developer.
     * @param s2 The secret speciality of the developer.
     * @param name The name of the developer.
     * @param money The salary of the developer.
     * @param year The year of employment for the developer.
     */
    Developer(Speciality s1, Speciality s2, QString name, int money, int year);

    /**
     * @brief Default constructor for creating an empty Developer object.
     */
    Developer();

    /**
     * @brief Getter function for retrieving the primary speciality of the developer.
     * @return The primary speciality of the developer.
     */
    Speciality getSpeciality();

    /**
     * @brief Getter function for retrieving the secret speciality of the developer.
     * @return The secret speciality of the developer.
     */
    Speciality getSecretSpeciality();
};

#endif // DEVELOPER_H
