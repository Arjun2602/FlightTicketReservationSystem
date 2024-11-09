#ifndef PASSENGER_H_INCLUDED
#define PASSENGER_H_INCLUDED

class Passenger
{
public:
    int passId;
    int noOfSeats;
    int journeyPrice;

    Passenger();
    Passenger(int passId, int noOfSeats, int journeyPrice);
};

#endif // PASSENGER_H_INCLUDED
