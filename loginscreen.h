#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QDialog>
#include "firstscreen.h"
#include "Gender.h"
#include "game.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QCoreApplication>

/**
 * @brief Class representing the login screen.
 *
 * The LoginScreen class enables the user to select their gender and input a username,
 * serving as a transition screen. It allows the user to return to the first screen and
 * proceed to the game screen after entering this information.
 */
namespace Ui {
class LoginScreen;
}

class LoginScreen : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for LoginScreen class.
     *
     * @param parent Pointer to the parent window as a QWidget.
     */
    explicit LoginScreen(QWidget *parent = nullptr);

    /**
     * @brief Destructor for LoginScreen class.
     */
    ~LoginScreen();

    static QString username; /**< Static username variable */

private slots:
    /**
     * @brief Click event of the "Woman" button.
     *
     * This slot function is called when the user clicks the "Woman" button.
     * It triggers the selection of the female gender and updates the label accordingly.
     * It also changes the appearance of the button to indicate selection.
     */
    void on_womanButton_clicked();

    /**
     * @brief Click event of the "Man" button.
     *
     * This slot function is called when the user clicks the "Man" button.
     * It triggers the selection of the male gender and updates the label accordingly.
     * It also changes the appearance of the button to indicate selection.
     */
    void on_manButton_clicked();

    /**
     * @brief Click event of the "Back" button.
     *
     * This slot function is called when the user clicks the "Back" button.
     * It enables the user to return to the previous screen (FirstScreen).
     */
    void on_backButton_clicked();

    /**
     * @brief Click event of the "Next" button.
     *
     * This slot function is called when the user clicks the "Next" button.
     * It checks for username and gender input, and if both are entered,
     * it proceeds to the next screen (GameScreen). If either is not entered,
     * it prevents moving to the next screen.
     */
    void on_nextButton_clicked();

    /**
     * @brief Event triggered when the text in the username field is edited.
     *
     * This slot function is triggered when the user edits the username field.
     * It ensures that no spaces are allowed in the username and limits the
     * character count of the entered username.
     *
     * @param arg1 The edited text in the username field.
     */
    void on_usernameLineEdit_textEdited(const QString &arg1);

private:
    Ui::LoginScreen *ui; /**< UI object */
    Gender gender; /**< Selected gender */
    bool isClicked; /**< Control for female or male push button */

};

#endif // LOGINSCREEN_H

