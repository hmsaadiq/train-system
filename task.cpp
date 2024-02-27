#include <iostream>
using namespace std;

void printSeats(int mass[13][6])
{
    cout << "\n\t---------------------------------------------------------\n";
    cout << "\t        T I C K E T    B O O K I N G    S Y S T E M\n";
    cout << "\t---------------------------------------------------------\n";
    cout << " This program books seats for a train from Paris to London.\n";
    cout << " The train contains 13 rows and 6 seats in each row as below:\n";
    int i, j;
    cout << " * indicates that the seat is available;\n";
    cout << " X indicates that the seat is occupied.\n ";
    cout << "Class  \tA\tB\tC\tD\tE\tF\n";
    for (i = 0; i < 2; i++)
    {
        cout << " F Row " << (i + 1);
        for (j = 0; j < 6; j++)
            if (mass[i][j] == 0)
                cout << "\t*";
            else
                cout << "\tX";
        cout << endl;
    }
    for (i = 2; i < 7; i++)
    {
        cout << " B Row " << (i + 1);
        for (j = 0; j < 6; j++)
            if (mass[i][j] == 0)
                cout << "\t*";
            else
                cout << "\tX";
        cout << endl;
    }
    for (i = 7; i < 13; i++)
    {
        cout << " E Row " << (i + 1);
        for (j = 0; j < 6; j++)
            if (mass[i][j] == 0)
                cout << "\t*";
            else
                cout << "\tX";
        cout << endl;
    }
}
int cost(int i)
{
    if (i < 2)
        return 400;
    else
        if (i < 7)
            return 300;
        else
            return 100;
}
int sumSeats(int mass[13][6])
{
    int s = 0;
    int i, j;
    for (i = 0; i < 13; i++)
        for (j = 0; j < 6; j++)
            s += mass[i][j] * cost(i);
    return s;
}
int main()
{
    int i;
    char seat,option=0;
    int mass[13][6] = { 0 };
    while (true)
    {
        printSeats(mass);
        if (option != 'p')
        {
            cout << "--------------------------------------------------------------------\n";
            cout << " Class Of Ticket       |     Rows available      |   Rate Per Ticket\n";
            cout << "--------------------------------------------------------------------\n";
            cout << " First Class ticket    |          1-2            |        $400\n";
            cout << " Business Class ticket |          3-7            |        $300\n";
            cout << " Economy Class ticket  |          8-13           |        $100\n";
            cout << "--------------------------------------------------------------------\n";

            cout << " Enter the row  (1-13) :  ";
            cin >> i;
            cout << " Enter the seat (A-F)  :  ";
            cin >> seat;

            if ((seat >= 'A') && (seat <= 'F') && (i >= 1) && (i <= 13))
            {
                if (mass[i - 1][seat - 'A'] == 0)
                {
                    mass[i - 1][seat - 'A'] = 1;
                    cout << "--------------------------------------------------------------------\n";
                    cout << " Now seat " << i << seat << " is reserved for You, cost = " << cost(i - 1);
                }
                else
                    cout << " But seat " << i << seat << " is already reserved , choose another one";
            }

            else
                cout << " Rows must be between 1 to " << 13 << ", seats in A,B,C,D,E,F";
            cout << endl;



            cout << " Total cost of seats = " << sumSeats(mass) << endl;
            cout << "--------------------------------------------------------------------\n";
            
        } 
	 cout << " Do you want continue? Y/y for yes, N/n for no, p/P to print the seating chart:\n ";
        cin >> option;
        if ((option == 'n') || (option == 'N'))
            break;
        if ((option == 'P') || (option == 'p'))
            void printSeats();
    }
    
    
   
    return 0;
}
