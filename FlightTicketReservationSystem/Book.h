#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include <iostream>
#include <string>
#include <map>

#include "Flight.h"

class Book
{
public:
    static std::map<int, Flight> flightMap;
    static int passId;
    // booking parts.......
    void initiateBooking();
    int calculatePrice(int flyId, int noOfseats);
    void decreSeatsIncrePrice(int flyId, int noOfseats);

    // Cancel Parts...........
    void initiateCancelling();
    void increaSeatDecrePrice(int flyId, int passId, int noOfSeats, int journeyPrice);
    void PrintSummary();
};

#endif // BOOK_H_INCLUDED
