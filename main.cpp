#include"function.h"

int main() 
{
    display();
    cout << endl;
    //startOfDay();
    cout << endl;
    purchaseTickets(0, 3);
    purchaseTickets(1, 20);
    purchaseTickets(2, 15);
    purchaseTickets(3, 8);
    cout << endl;
    displayPassengerInfo();
    cout << endl;
    displayTotalInfo();
    cout << endl;
    displayMostPassengers();
    return 0;
}
