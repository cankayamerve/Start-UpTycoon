#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "user.h"
#include <QDialog>
#include "firstscreen.h"

/**
 * @file
 * @brief Defines the ScoreBoard class.
 */

/**
 * @brief Class representing the scoreboard.
 *
 * The ScoreBoard class represents the scoreboard displaying the top three users
 * who have completed the game in the least amount of time.
 * It allows users to view these top scores and contains functionality to return
 * to the main screen by clicking the back button.
 */
namespace Ui {
class ScoreBoard;
}

class ScoreBoard : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for the ScoreBoard class.
     *
     * @param parent Pointer to the parent window as a QWidget.
     */
    explicit ScoreBoard(QWidget *parent = nullptr);

    /**
     * @brief Destructor for the ScoreBoard class.
     */
    ~ScoreBoard();

    static QString labelsString[3]; /**< Static array to hold labels for top 3 users */

private slots:
    /**
     * @brief Click event of the "Back" button.
     *
     * This slot function is called when the user clicks the "Back" button.
     * It enables the user to return to the main screen (FirstScreen).
     */
    void on_backScoreButton_clicked();

private:
    Ui::ScoreBoard *ui; /**< UI object */
};

#endif // SCOREBOARD_H
