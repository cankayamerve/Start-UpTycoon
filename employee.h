#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<QString>

/**
 * @brief The Employee class represents an individual employee with essential attributes.
 *
 * This class encapsulates information about an employee, including their name, salary,
 * employment year, and a unique identifier. The unique identifier is automatically assigned
 * and incremented for each new employee, ensuring a distinct identification for each instance.
 *
 * The class provides methods for retrieving and modifying the employee's name, salary, and
 * employment year. Additionally, it includes a friend function for comparing employees based on
 * their unique identifier (id).
 *
 * Usage example:
 * \code
 *     Employee emp1("Buse Nur İleri", 50000, 2019);
 *     Employee emp2("Merve Çankaya", 60000, 2023);
 * \endcode
 */

class Employee
{
private:
    QString name;   ///< The name of the employee.
    int salary;     ///< The salary of the employee.
    int year;       ///< The year of employment for the employee.
    int id;         ///< The unique identifier for the employee.
    static int count;  ///< The static counter for generating unique employee identifiers.

public:
    /**
     * @brief Default constructor for creating an empty Employee object.
     */
    Employee();

    /**
     * @brief Parameterized constructor for creating an Employee object with specified attributes.
     * @param name The name of the employee.
     * @param salary The salary of the employee.
     * @param year The year of employment for the employee.
     */
    Employee(QString name, int salary, int year);

    /**
     * @brief Getter function for retrieving the name of the employee.
     * @return The name of the employee.
     */
    QString getName();

    /**
     * @brief Getter function for retrieving the salary of the employee.
     * @return The salary of the employee.
     */
    int getSalary();

    /**
     * @brief Getter function for retrieving the employment year of the employee.
     * @return The employment year of the employee.
     */
    int getYear();

    /**
     * @brief Setter function for modifying the employment year of the employee.
     * @param year The new employment year to be set.
     */
    void setYear(int year);

    /**
     * @brief Overloaded equality operator for comparing employees based on their unique identifiers.
     * @param emp1 The first employee to compare.
     * @param emp2 The second employee to compare.
     * @return True if the employees have the same unique identifier, false otherwise.
     */
    friend bool operator==(const Employee& emp1, const Employee& emp2);

};

#endif // EMPLOYEE_H
