#ifndef RESULTSCREEN_H
#define RESULTSCREEN_H

#include <QDialog>
#include "firstscreen.h"

namespace Ui {
class resultscreen;
}

/**
 * @brief The resultscreen class represents a dialog for displaying game results.
 *
 * This class inherits from QDialog and provides functionality for showing a result screen
 * with options for the user to interact with. It includes methods for setting the background
 * based on whether the user wins or loses the game. The class also contains a slot for handling
 * button clicks, enhancing user interaction.
 *
 * Usage example:
 * \code
 *     resultscreen resultDialog;
 *     resultDialog.winningBackground(); // Set the background for a winning scenario
 *     resultDialog.exec(); // Display the result dialog
 * \endcode
 */
class resultscreen : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for creating a resultscreen object.
     * @param parent The parent widget (default is nullptr).
     */
    explicit resultscreen(QWidget *parent = nullptr);

    /**
     * @brief Method for setting the background for a winning scenario.
     */
    void winningBackground();

    /**
     * @brief Method for setting the background for a losing scenario.
     */
    void losingBackground();

    /**
     * @brief Destructor for cleaning up resources when the resultscreen is destroyed.
     */
    ~resultscreen();

private slots:
    /**
     * @brief Slot for handling button clicks in the result screen.
     */
    void on_pushButton_clicked();

private:
    Ui::resultscreen *ui; ///< The user interface components for the resultscreen.
};

#endif // RESULTSCREEN_H
