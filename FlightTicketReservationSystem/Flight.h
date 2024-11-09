#ifndef FLIGHT_H_INCLUDED
#define FLIGHT_H_INCLUDED
#include <map>
#include <string>

#include "Passenger.h"
class Flight
{
public:
    int flyId;
    int seats;
    int price;
    std::map<int, Passenger> passList;

    Flight();
    Flight(int id);
};

#endif // FLIGHT_H_INCLUDED
