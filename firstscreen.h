#ifndef FIRSTSCREEN_H
#define FIRSTSCREEN_H

#include <QDialog>
#include "loginscreen.h"
#include "scoreboard.h"

/**
 * @brief Class representing the initial screen.
 *
 * This class creates the first screen that appears when the application starts.
 * It provides options for the user to log in or view the top scores.
 */
namespace Ui {
class FirstScreen;
}

class FirstScreen : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for the FirstScreen class.
     *
     * @param parent Pointer to the parent window as a QWidget.
     */
    explicit FirstScreen(QWidget *parent = nullptr);

    /**
     * @brief Destructor for the FirstScreen class.
     */
    ~FirstScreen();

private slots:
    /**
     * @brief Click event of the "Start" button.
     *
     * This slot function is called when the user clicks the "Start" button.
     * It directs the user to the login screen.
     */
    void on_startButton_clicked();

    /**
     * @brief Click event of the "Score" button.
     *
     * This slot function is called when the user clicks the "Score" button.
     * It navigates the user to the Scoreboard screen, displaying the top three scores.
     */
    void on_scoreButton_clicked();

private:
    Ui::FirstScreen *ui; /**< UI object */
};

#endif // FIRSTSCREEN_H
