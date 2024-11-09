#include "Book.h"


std::map<int, Flight> Book::flightMap;
int Book::passId = 1;
// *************************************** Initiate Booking....
void Book::initiateBooking()
{
    int flyId;
    int noOfseats;
    std::cout << "\nEnter Flight Id: ";
    std::cin >> flyId;

    if(flightMap.find(flyId) == flightMap.end()){
        std::cout << "\nInvalid Flight Id!";
        return;
    }
    Flight f = flightMap[flyId];
    std::cout << "\nFlight Id: " << f.flyId << " Remaining seats: " << f.seats << " Current Ticket Price: " << f.price;
    std::cout << "\nEnter no of Tickets: ";
    std::cin >> noOfseats;
    if(noOfseats > f.seats){
        std::cout << "\nNo seats available!!";
        return;
    }
    int journeyPrice = calculatePrice(flyId, noOfseats);
    int Id = passId;
    Book::flightMap[flyId].passList[Id] = Passenger(Id, noOfseats, journeyPrice);
    Book::passId++;

    decreSeatsIncrePrice(flyId, noOfseats);
    std::cout << "\nBooked Successfully!!";
}

// ********************************decrease the seats & Increase the Price

void Book::decreSeatsIncrePrice(int flyId, int noOfSeats)
{
    int actualSeats = 0;
    int actualPrice = 0;
    int finalPrice = 0;
    int finalSeats = 0;
    int extraPrice = 0;
    Flight f = flightMap[flyId];
    actualPrice = f.price;
    actualSeats = f.seats;
    extraPrice = noOfSeats * 200;
    finalSeats = actualSeats - noOfSeats;
    finalPrice = actualPrice + extraPrice;

    Book::flightMap[flyId].price = finalPrice;
    Book::flightMap[flyId].seats = finalSeats;

}

// ************************************ calculate the current journey Price

int Book::calculatePrice(int flyId, int noOfseats)
{
    Flight f = flightMap[flyId];
    int currentPrice = f.price;

    int totalPrice = currentPrice * noOfseats;
    return totalPrice;
}

// ************************************  print the flights
void Book::PrintSummary()
{
    for(auto it = flightMap.begin(); it != flightMap.end(); it++){
        Flight f = it->second;

        std::cout << " FlyId: " << f.flyId << " Seats: " << f.seats << " Price: " << f.price;

        std::map<int, Passenger> tempPass = f.passList;
        for(auto i = tempPass.begin(); i != tempPass.end(); i++)
        {
            Passenger p = i->second;
            std::cout << "\nPass Id: " << p.passId << " No of seats: " << p.noOfSeats << " Cost Price: " << p.journeyPrice;
        }
        std::cout << std::endl;
    }
}

void Book::initiateCancelling()
{
    int flyId;
    int passId;
    int noOfSeats = 0;
    int journeyPrice = 0;
    std::cout << "\nEnter flight Id: ";
    std::cin >> flyId;

    if(Book::flightMap.find(flyId) == flightMap.end()){
        std::cout << "\nInvalid Flight ID!!";
        return;
    }

    Flight f = flightMap[flyId];
    std::map<int, Passenger> passList = f.passList;

    std::cout << "\nEnter Pass ID: ";
    std::cin >> passId;

    if(passList.find(passId) == passList.end()){
        std::cout << "\nInvalid Pass ID!!";
        return;
    }

    Passenger p = passList[passId];
    noOfSeats = p.noOfSeats;
    journeyPrice = p.journeyPrice;

    increaSeatDecrePrice(flyId, passId, noOfSeats, journeyPrice);
    // need to remove passenger from passMap
    Book::flightMap[flyId].passList.erase(passId);
    std::cout << "\nCancelled Successfully!! Amount will be refund in 24 hrs!!";
}

// ************************************************** increase the seats & decrease the price!
void Book::increaSeatDecrePrice(int flyId, int passId, int noOfSeats, int journeyPrice)
{
    int actualPrice = 0;
    int actualSeats = 0;
    int finalPrice = 0;
    int finalSeats = 0;

    Flight f = flightMap[flyId];

    actualPrice = f.price;
    actualSeats = f.seats;
    int costTodecrease = 200 * noOfSeats;
    finalSeats = actualSeats + noOfSeats;
    finalPrice = actualPrice - costTodecrease;

    Book::flightMap[flyId].price = finalPrice;
    Book::flightMap[flyId].seats = finalSeats;
}
