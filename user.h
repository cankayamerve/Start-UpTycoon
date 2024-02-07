#ifndef USER_H
#define USER_H

#include <QString>
#include "project.h"
#include "developer.h"

/**
 * @file
 * @brief Defines the User class.
 */

/**
 * @brief Class representing a user.
 *
 * The User class represents a user in the system. It contains attributes such as
 * the user's name, rounds played, available money, owned projects, and developers
 * hired by the user. It includes functionalities to manage projects, developers,
 * match developers with projects, and handle user-specific operations.
 */
class User
{
private:
    QString name; /**< Name of the user */
    int round; /**< Number of rounds played */
    double money; /**< Available money of the user */
    std::vector<Project> projects; /**< Projects owned by the user */
    std::vector<Developer> developers; /**< Developers hired by the user */

public:
    /**
     * @brief Constructor for the User class.
     *
     * @param name Name of the user as a QString.
     */
    User(QString name);

    /**
     * @brief Method to set the name of the user.
     *
     * @param name Name of the user as a QString.
     */
    void setName(QString name);

    /**
     * @brief Method to retrieve the name of the user.
     *
     * @return Name of the user as a QString.
     */
    QString getName() const;

    /**
     * @brief Method to set the round played by the user.
     *
     * @param round Number of rounds played by the user.
     */
    void setRound(int round);

    /**
     * @brief Method to retrieve the rounds played by the user.
     *
     * @return Number of rounds played by the user.
     */
    int getRound();

    /**
     * @brief Method to set the available money of the user.
     *
     * @param money Available money of the user.
     */
    void setMoney(double money);

    /**
     * @brief Method to retrieve the available money of the user.
     *
     * @return Available money of the user.
     */
    double getMoney();

    /**
     * @brief Method to retrieve the list of projects owned by the user.
     *
     * @return A reference to the vector of Project objects owned by the user.
     */
    std::vector<Project>& getProjects();

    /**
     * @brief Overloaded equality operator to compare two User objects.
     *
     * @param other First User object to be compared.
     * @param other2 Second User object to be compared.
     * @return True if both users are equal, otherwise false.
     */
    friend bool operator==(const User& other, const User& other2);

    /**
     * @brief Method to add a project to the user's list of owned projects.
     *
     * @param p Project object to be added to the user's projects.
     */
    void addProject(Project p);

    /**
     * @brief Method to delete a project from the user's list of owned projects.
     *
     * @param p Project object to be deleted from the user's projects.
     */
    void deleteProject(Project p);

    /**
     * @brief Method to match an employee (developer) with a project.
     *
     * @param e Employee (Developer) object to be matched with a project.
     */
    void matching(Employee e);

    /**
     * @brief Method to add a developer to the user's list of hired developers.
     *
     * @param d Developer object to be added to the user's developers.
     */
    void addDeveloper(Developer d);

    /**
     * @brief Method to delete a developer from the user's list of hired developers.
     *
     * @param d Developer object to be deleted from the user's developers.
     */
    void deleteDeveloper(Developer d);

    /**
     * @brief Method to retrieve a project by its name from the user's owned projects.
     *
     * @param projectName Name of the project to be retrieved.
     * @return Project object with the specified name.
     */
    Project getProjectWithName(QString projectName);

    /**
     * @brief Method to retrieve a developer by their name from the user's hired developers.
     *
     * @param devName Name of the developer to be retrieved.
     * @return Developer object with the specified name.
     */
    Developer getDeveloperWithName(QString devName);

    /**
     * @brief Method to retrieve the list of developers hired by the user.
     *
     * @return A reference to the vector of Developer objects hired by the user.
     */
    std::vector<Developer>& getDevelopers();
};

#endif // USER_H
