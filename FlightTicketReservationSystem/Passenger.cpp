#include "Passenger.h"

Passenger::Passenger()
:passId(0), noOfSeats(0),journeyPrice(0)
{
}
Passenger::Passenger(int passId, int noOfSeats, int journeyPrice)
{
    this->passId = passId;
    this->noOfSeats = noOfSeats;
    this->journeyPrice = journeyPrice;
}
