#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include <QStringListModel>
#include <QListWidgetItem>
#include "firstscreen.h"
#include "user.h"
#include "loginscreen.h"
#include "string"
#include "random"
#include "employee.h"
#include "developer.h"
#include "speciality.h"
#include <QRandomGenerator>
#include <cstdlib>
#include <QDebug>
#include <QListWidgetItem>
#include "resultscreen.h"
#include <QColor>

namespace Ui {
class Game;
}

/**
 * @brief The Game class represents the main game interface and logic.
 *
 * This class inherits from QDialog and provides the main gameplay logic and user interface
 * for the game. It includes methods for generating random developers, calculating salaries,
 * managing user income, updating the game state, saving and reading user data, and handling
 * various button clicks and interactions within the game.
 *
 * Usage example:
 * \code
 *     Game gameDialog;
 *     gameDialog.updateGame(); // Update the game state
 *     gameDialog.exec(); // Display the game dialog
 * \endcode
 */
class Game : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for creating a Game object.
     * @param parent The parent widget (default is nullptr).
     */
    explicit Game(QWidget *parent = nullptr);

    /**
     * @brief Method for getting a random image path for employees.
     * @return A random image path.
     */
    QString getRandomEmpImage();

    /**
     * @brief Method for generating a random number.
     * @return A random number.
     */
    int generateRandomNumber();

    /**
     * @brief Method for converting a Speciality enum to a string.
     * @param spc The Speciality enum value.
     * @return A string representation of the Speciality.
     */
    static QString specialityEnumToString(Speciality spc);

    /**
     * @brief Method for updating the game state.
     */
    void updateGame();

    /**
     * @brief Method for calculating salaries.
     */
    void salaryCalculator();

    /**
     * @brief Method for managing user income.
     */
    void income();

    /**
     * @brief Method for disabling buttons during specific game events.
     */
    void disablingButtons();

    /**
     * @brief Method for saving user data to a file.
     */
    void saveUserDataToFile();

    /**
     * @brief Method for reading user data from a file.
     */
    void readUserDataFromFile();

    /**
     * @brief Method for printing information about the least three rounds.
     */
    void printLeastThreeRounds();

    /**
     * @brief when user win the game to read rounds and names all of winning user from txt we create vector
     * and use that vector to obtain top 3 winning user name and round
     */
    std::vector<int> rounds;
    std::vector<QString> names;

    /**
     * @brief Method for changing the widget color.
     */
    void changeWidgetColor();

    /**
     * @brief Destructor for cleaning up resources when the Game is destroyed.
     */
    ~Game();

private slots:
    /**
     * @brief Slot for handling the "Back" button click.
     */
    void on_gamebackbutton_clicked();

    /**
     * @brief Slot for handling the "Next" button click.
     */
    void on_gamenextbutton_clicked();

    /**
     * @brief Slot for handling the "Delete Project" button click.
     */
    void on_deleteprojebutton_clicked();

    /**
     * @brief Slot for handling the "Delete Developer" button click.
     */
    void on_deletedeveloperbutton_clicked();

    /**
     * @brief Slot for handling the "Buy Developer 1" button click.
     */
    void on_buydeveloper1button_clicked();

    /**
     * @brief Slot for handling the "Buy Developer 2" button click.
     */
    void on_buydeveloper2button_clicked();

    /**
     * @brief Slot for handling the "Buy Developer 3" button click.
     */
    void on_buydeveloper3button_clicked();

    /**
     * @brief Slot for handling the "Buy Developer 4" button click.
     */
    void on_buydeveloper4button_clicked();

    /**
     * @brief Slot for handling the "Buy Developer 5" button click.
     */
    void on_buydeveloper5button_clicked();

    /**
     * @brief Slot for handling item clicks in the "Buy Project" widget.
     */
    void on_buyprojectwidget_itemClicked(QListWidgetItem *item);

    /**
     * @brief Slot for handling the "Buy Now" button click.
     */
    void on_buynowbutton_clicked();

    /**
     * @brief Slot for handling item clicks in the "Project List" widget.
     */
    void on_projectListWidget_itemClicked(QListWidgetItem *item);

    /**
     * @brief Slot for handling item clicks in the "Developer List" widget.
     */
    void on_developerListWidget_itemClicked(QListWidgetItem *item);

    /**
     * @brief Slot for handling the "Matching" button click.
     */
    void on_matchingButton_clicked();

private:
    Ui::Game *ui; ///< The user interface components for the Game.
    User currentUser; ///< The current user playing the game.
    QString img[31]; ///< Holds all image paths for employees.
    std::vector<int> intVector; ///< Holds different random numbers for image and name selection.
    QListWidgetItem *selectedWidgetItemProject; ///< Selected item in the "Buy Project" widget.
    QListWidgetItem *selectedWidgetItemDeveloper; ///< Selected item in the "Developer List" widget.
    std::vector<QString> name; ///< Vector to hold names.
    std::vector<QString> surname; ///< Vector to hold surnames.
    std::vector<QString> namesOfEmployees; ///< Vector to hold names of employees.
    Developer generateRandomDeveloper(); ///< Method to generate a random developer.
    QString generateRandomFullname(); ///< Method to generate a random full name with above name and surname vector
    int generateRandomMoney(); ///< Method to generate a random amount of money.
    Speciality getRandomSpeciality(); ///< Method to get a random speciality.
    bool buyProjectButtonIsCLicked; ///< Boolean to control buying just one project in a year.
    bool buyDeveloperButtonIsCLicked; ///< Boolean to check if a developer was hired within the year.
    QString selectedProjectName; ///< Name of the selected project.
    int projectNameCount; ///< Counter for the project name to obtain different project each year.
    Developer developerArray[5]; ///< Array to hold developers. ( They can be hired by user )
    Project projectArray[3]; ///< Array to hold projects. (They can be bought by user )
};

#endif // GAME_H
