#include <iostream>
#include <map>
#include <string>

#include "Flight.h"
#include "Book.h"
using namespace std;



void createFlights()
{
    for(int i = 1; i <= 2; i++){
        Book::flightMap[i] = Flight(i);
    }
}
void module()
{
    cout << "\n1)Book Ticket";
    cout << "\n2)Cancel Ticket";
    cout << "\n3)Print Flight Summary";
    cout << "\n4)Exit\n";
}
int main()
{
    cout << "\t\tXYZ flight!!" << endl;
    createFlights();
    bool flag = true;
    int choice = 0;
    while(flag)
    {
        module();
        cin >> choice;
        switch(choice)
        {
        case 1:
            {
                // book
                Book b;
                b.initiateBooking();
                break;
            }
        case 2:
            {
                // cancel
                Book b;
                b.initiateCancelling();
                break;
            }
        case 3:
            {
                // print ticket summary
                Book b;
                b.PrintSummary();
                break;
            }
        case 4:
            {
                // exit
                flag = false;
                cout << "\nThanks for visiting XYZ Flight!!!!";
                break;
            }
        default:
            {
                cout << "\nInvalid!! Try again!!";
                break;
            }
        }
    }
}
