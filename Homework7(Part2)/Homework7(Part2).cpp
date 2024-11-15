#include <iostream>
#include <ctime>
#include <cctype>

using namespace std;

const int ROWS = 13;
const int COLUMNS = 6;

bool makeReservation(char[][COLUMNS], int, char);

void generateSeats(char[][COLUMNS]);
void displaySeats(char[][COLUMNS]);

int main()
{
    srand(time(0));

    char airplaneSeats[ROWS][COLUMNS];

    int choice;

    bool repeat = true;

    generateSeats(airplaneSeats);

    do
    {
        cout << "Enter a menu option (1 - Display Seats, 2 - Reserve Seat, 3 - Quit): ";
        cin >> choice;

        cout << "\n";

        switch (choice)
        {
        case 1:

            displaySeats(airplaneSeats);

            break;
        case 2:

            int row;
            
            char column;

            cout << "Enter the row number and column letter you want to reserve in that order. (Seperate with a space): ";
            cin >> row >> column;

            while (row < 1 && row > 13 && column < 'a' && column > 'f')
            {
                cout << "Invalid input. Please Enter the row number and column letter you want to reserve in that order. (Seperate with a space): ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max());
                cin >> row >> column;
            }

            if (makeReservation(airplaneSeats, row, toupper(column)))
            {
                cout << "Seat has been reserved.\n\n";
            }
            else
            {
                cout << "Seat already reserved.\n\n";
            }

            displaySeats(airplaneSeats);

            break;
        case 3:

            repeat = false;

            break;
        default:

            cout << "Invalid input.\n\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while ((choice != 1 && choice != 2 && choice != 3) || repeat);

    return 0;
}

void generateSeats(char seats[][COLUMNS])
{
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLUMNS; c++)
        {
            int random = rand() % 2 + 1;

            if (random == 1)
            {
                seats[r][c] = '*';
            }
            else
            {
                seats[r][c] = 'X';
            }
        }
    }
}

void displaySeats(char seats[][COLUMNS])
{
    char columnLetter = 'A';

    cout << "'*' - Empty\t'X' - Taken\n\n";

    cout << "\t";

    for (int i = 0; i < COLUMNS; i++)
    {
        if (i == 3)
        {
            cout << "\t";
        }

        cout << columnLetter << " ";
        columnLetter++;
    }

    cout << "\n\n";

    for (int r = 0; r < ROWS; r++)
    {
        cout << "Row " << r + 1 << "\t";

        for (int c = 0; c < COLUMNS; c++)
        {
            if (c == 3)
            {
                cout << "\t";
            }

            cout << seats[r][c] << " ";
        }
        cout << "\n";
    }

    cout << "\n";
}

bool makeReservation(char seats[][COLUMNS], int row, char column)
{
    row -= 1;
    column -= 65;

    if (seats[row][column] == '*')
    {
        seats[row][column] = 'X';

        return true;
    }

    return false;
}

/*
Output:

Enter a menu option (1 - Display Seats, 2 - Reserve Seat, 3 - Quit): 1

'*' - Empty     'X' - Taken

        A B C   D E F

Row 1   * * *   * X X
Row 2   * X X   X * *
Row 3   * X *   * X *
Row 4   * X X   * * X
Row 5   * * X   * * *
Row 6   X * X   X X X
Row 7   X * *   X * *
Row 8   * * *   X * X
Row 9   * X X   * * X
Row 10  X * *   * * X
Row 11  X X X   * * *
Row 12  * * X   X X X
Row 13  * X X   X X X

Enter a menu option (1 - Display Seats, 2 - Reserve Seat, 3 - Quit): 2

Enter the row number and column letter you want to reserve in that order. (Seperate with a space): 5 f
Seat has been reserved.

'*' - Empty     'X' - Taken

        A B C   D E F

Row 1   * * *   * X X
Row 2   * X X   X * *
Row 3   * X *   * X *
Row 4   * X X   * * X
Row 5   * * X   * * X
Row 6   X * X   X X X
Row 7   X * *   X * *
Row 8   * * *   X * X
Row 9   * X X   * * X
Row 10  X * *   * * X
Row 11  X X X   * * *
Row 12  * * X   X X X
Row 13  * X X   X X X

Enter a menu option (1 - Display Seats, 2 - Reserve Seat, 3 - Quit): 2

Enter the row number and column letter you want to reserve in that order. (Seperate with a space): 1 e
Seat already reserved.

'*' - Empty     'X' - Taken

        A B C   D E F

Row 1   * * *   * X X
Row 2   * X X   X * *
Row 3   * X *   * X *
Row 4   * X X   * * X
Row 5   * * X   * * X
Row 6   X * X   X X X
Row 7   X * *   X * *
Row 8   * * *   X * X
Row 9   * X X   * * X
Row 10  X * *   * * X
Row 11  X X X   * * *
Row 12  * * X   X X X
Row 13  * X X   X X X

Enter a menu option (1 - Display Seats, 2 - Reserve Seat, 3 - Quit): 3

*/
