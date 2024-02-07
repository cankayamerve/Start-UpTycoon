#ifndef PROJECT_H
#define PROJECT_H

#include "speciality.h"
#include "developer.h"
#include "manager.h"

/**
 * @file
 * @brief Defines the Project class.
 */

/**
 * @brief Class representing a project.
 *
 * The Project class represents a software development project. It contains attributes
 * such as the project's name, specialization, developers involved, cost, manager, and ID.
 * It allows adding and deleting developers, obtaining project details, calculating
 * the manager's cost, and accessing project-related information.
 */
class Project
{
private:
    QString name; /**< Name of the project */
    Speciality speciality; /**< Specialization of the project */
    std::vector<Developer> developersinProject; /**< Developers involved in the project */
    int cost; /**< Cost of the project */
    Manager m; /**< Manager of the project */
    static int count; /**< Static count variable */
    int id; /**< ID of the project */

public:
    /**
     * @brief Constructor to initialize a Project object with given attributes.
     *
     * @param name Name of the project as a QString.
     * @param speciality Speciality of the project as a Speciality enum.
     * @param cost Cost of the project as an integer.
     */
    Project(QString name, Speciality speciality, int cost);

    /**
     * @brief Default constructor for the Project class.
     */
    Project();

    /**
     * @brief Method to add a developer to the project.
     *
     * @param d Developer object to be added.
     */
    void addDeveloperinProject(Developer d);

    /**
     * @brief Method used to dismiss a developer from employment if the project is deleted.
     *
     * This method is intended to remove a developer from employment in the event that the project
     * they are associated with is deleted. It takes a Developer object as a parameter and marks
     * the developer as dismissed from the project's team. If the associated project is removed or
     * deleted, this function can be used to update the developer's employment status.
     *
     * @param d The Developer object whose employment is to be terminated if the project is deleted.
     */
    void deleteDeveloperinProject(Developer d);


    /**
     * @brief Method to retrieve the name of the project.
     *
     * @return The name of the project as a QString.
     */
    QString getName();

    /**
     * @brief Method to retrieve the cost of the project.
     *
     * @return The cost of the project as an integer.
     */
    int getCost();

    /**
     * @brief Overloaded equality operator to compare two Project objects.
     *
     * @param pro1 First Project object to be compared.
     * @param pro2 Second Project object to be compared.
     * @return True if both projects are equal, otherwise false.
     */
    friend bool operator==(const Project& pro1, const Project& pro2);

    /**
     * @brief Method to retrieve the specialization of the project.
     *
     * @return The specialization of the project as a Speciality enum.
     */
    Speciality getSpeciality();

    /**
     * @brief Method to calculate the manager's cost for the project.
     *
     * @return The cost of the manager as an integer.
     */
    int managerCost();

    /**
     * @brief Method to retrieve the developers involved in the project.
     *
     * @return A reference to the vector of Developer objects in the project.
     */
    std::vector<Developer>& getDevelopersinProject();
};

#endif // PROJECT_H
