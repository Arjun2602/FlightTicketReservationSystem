#include "Flight.h"


Flight::Flight()
:flyId(0), seats(0), price(0), passList()
{
}

Flight::Flight(int id)
{
    this->flyId = id;
    seats = 50;
    price = 5000;
}
