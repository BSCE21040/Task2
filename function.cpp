#include"function.h"

//declaring the constant values globally
const int coach = 6;
const int seats = 80;
const int totalSeats = coach * seats;
int trains[4][2] = { { 9, totalSeats }, { 11, totalSeats }, { 1, totalSeats }, { 3, totalSeats } };
//int trains[4][2];
//initialize counts of passengers and revenue
int upJourney[4] = { 0, 0, 0, 0 };
int downJourney[4] = { 0, 0, 0, 0 };
float upRevenue[4] = { 0.0, 0.0, 0.0, 0.0 };
float downRevenue[4] = { 0.0, 0.0, 0.0, 0.0 };

//displaying the time 
void display()
{
    cout << endl;
    cout << "-------------------------------------------" << endl;
    cout << "\t  Schedule of Trains " << endl;
    cout << "-------------------------------------------" << endl;
    //schedule display
    cout << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << "Departure Time: " << trains[i][0] << ":00" << "  -  " << "Return Time: " << trains[i][0] + 1 << ":00" << endl;
    }
    cout << "-------------------------------------------" << endl;
}

void startOfDay()
{
    cout << "\t  Railway Ticket Booking" << endl;
    cout << endl;
    cout << "-------------------------------------------" << endl;
    cout << "\t  Up Journeys" << endl;
    cout << "-------------------------------------------" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << trains[i][0] << ":00" << "  ->Available Seats: " << trains[i][1] << endl;
    }
    cout << "-------------------------------------------" << endl;
    cout << endl;
    cout << "\t  Down Journeys" << endl;
    cout << "-------------------------------------------" << endl;
    for (int i = 0; i < 4; i++)
    {
        if (i == 3) 
        {
            cout << trains[i][0] << ":00" << "  -> Available Seats: " << trains[i][1] << " (2 extra coaches)" << endl;
        }
        else
        {
            cout << trains[i][0] << ":00" << "  -> Available Seats: " << trains[i][1] << endl;
        }
    }
    cout << "-------------------------------------------" << endl;
    //initialize passenger count and revenue to 0
    for (int i = 0; i < 4; i++) 
    {
        upJourney[i] = 0;
        downJourney[i] = 0;
        upRevenue[i] = 0.0;
        downRevenue[i] = 0.0;
    }
}

void purchaseTickets(int trainNum, int numTickets)
{
    float totalPrice;
    if (trainNum >= 0 && trainNum < 4)
    {
        //check if seats are available 
        if (numTickets > 0 && trains[trainNum][1] >= numTickets) 
        {
            //calculate total 
            totalPrice = numTickets * 25.0;
            if (trainNum < 3)
            {
                upJourney[trainNum] = upJourney[trainNum] + numTickets;
                upRevenue[trainNum] = upRevenue[trainNum] + totalPrice;
            }
            else 
            {
                downJourney[trainNum - 3] = downJourney[trainNum - 3] + numTickets;
                downRevenue[trainNum - 3] = downRevenue[trainNum - 3] + totalPrice;
            }
            //reducing the count of seats
            trains[trainNum][1] = trains[trainNum][1] - numTickets;
            //cout << numTickets << " Tickets Booked for Train Number " << trainNum + 1 << endl;
        }
        else 
        {
            cout << "Seats are Not Avalible for " << trainNum + 1 << " or Invalid Ticket Number!" << endl;
        }
    }
    else 
    {
        cout << "Invalid Train Number!" << endl;
    }
}

void displayPassengerInfo() 
{
    cout << "Passenger Information:" << endl;
    //up journey
    cout << "Up Journeys:" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << "Train " << i + 1 << " -> Passengers: " << upJourney[i] << " Revenue: $" << upRevenue[i] << endl;
    }
    //down journey
    cout << endl << "Down Journeys:" << endl;
    for (int i = 0; i < 4; i++)
    {
        if (i == 3) 
        {
            cout << "Train " << i + 1 << " -> Passengers: " << downJourney[i - 3] << " Revenue: $" << downRevenue[i - 3] << " (2 extra coaches)" << endl;
        }
        else 
        {
            cout << "Train " << i + 1 << " -> Passengers: " << downJourney[i] << " Revenue: $" << downRevenue[i] << endl;
        }
    }
    cout << endl;
}


void displayTotalInfo() 
{
    int totalPassengers = 0;
    float totalRevenue = 0.0;
    for (int i = 0; i < 4; i++) 
    {
        totalPassengers = totalPassengers + upJourney[i] + downJourney[i];
        totalRevenue = totalRevenue + upRevenue[i] + downRevenue[i];
    }
    cout << "Total Passengers for the day: " << totalPassengers << endl;
    cout << "Total Revenue for the day: $" << totalRevenue << endl;
}

void displayMostPassengers() 
{
    int maxPassengers = 0;
    int maxIndex = -1;

    for (int i = 0; i < 4; i++)
    {
        int totalPassengers = upJourney[i] + downJourney[i];
        if (totalPassengers > maxPassengers) 
        {
            maxPassengers = totalPassengers;
            maxIndex = i;
        }
    }
    if (maxIndex != -1) 
    {
        cout << "Train " << maxIndex + 1 << " had the most passengers today with " << maxPassengers << " passengers." << endl;
    }
    else 
    {
        cout << "No data available." << endl;
    }
}



//void bookTicket()
//{
//    int bookedTickets = 0;
//    while (true)
//    {
//        int choice;
//        cout << "1. Book Ticket" << endl;
//        cout << "2. Exit" << endl;
//        cin >> choice;
//        if (choice == 1)
//        {
//            
//        }
//        else if (choice == 2)
//        {
//            break;
//        }
//    }
//}


