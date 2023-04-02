#include <stdio.h>
#include <stdint.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef struct time
{
    int hour;
    int minute;
}time;

//--------------------------- FLight Class ------------------
class Flight
{
    private:
        string Id;
        string origin;
        string destination;
        time departureTime;
        time arrivalTime;
        int availableSeat;
    public:

        Flight(string Origin, string Destination,time departureTime, time arrivalTime, int availableSeat);
        void setOrigin(string Origin);
        void setDestination(string Destination);
        void setAvailableSeat(int availableSeat);
        void setDepartureTime(time departureTime);
        void setArrivalTime(time arrivalTime);

        string getId() const;
        string getOrigin() const;
        string getDestination() const;
        int getAvailableSeat() const;
        time getDepartureTime() const;
        time getArrivalTime() const;
};

//---------------------------Constructor of FLight Class ------------------

Flight::Flight(string Origin, string Destination,time departureTime, time arrivalTime, int availableSeat)
{
    static int count = 1;
    Flight::Id = "A";
    Flight::Id.append(to_string(count));
    count++;
    Flight::origin = Origin;
    Flight::destination = Destination;
    Flight::departureTime = departureTime;
    Flight::arrivalTime = arrivalTime;
    Flight::availableSeat = availableSeat;
}

//--------------------------- Setter Method of FLight Class ------------------

void Flight::setOrigin(string Origin)
{
    Flight::origin = Origin;
}
void Flight::setDestination(string Destination)
{
    Flight::destination = Destination;
}
void Flight::setAvailableSeat(int availableSeat)
{
    Flight::availableSeat = availableSeat;
}

void Flight::setDepartureTime(time departureTime)
{
    Flight::departureTime = departureTime;
}

void Flight::setArrivalTime(time arrivalTime)
{
    Flight::arrivalTime = arrivalTime;
}
//--------------------------- Getter method FLight Class ------------------
string Flight::getId() const
{
    return Flight::Id;
}

string Flight::getOrigin() const
{
    return Flight::origin;
}

string Flight::getDestination() const
{
    return Flight::destination;
}

int Flight::getAvailableSeat() const
{
    return Flight::availableSeat;
}

time Flight::getDepartureTime() const
{
    return Flight::departureTime;
}

time Flight::getArrivalTime() const
{
    return Flight::arrivalTime;
}
//--------------------------- Booking Class ------------------
class Booking
{
    private:
        int Id;
        string customerName;
        string flightId;
        int seatNumber;
    public:
        Booking(string customerName, string flightId, int seatNumber);
        void setCustomerName(string Name);
        void setFlightId(string flightId);
        void setSeatNumber(int seatNumber);

        int getId() const;
        string getCustomerName() const;
        string getFlightId() const;
        int getSeatNumber() const;
};

//--------------------------- Constructor of Booking Class ------------------
Booking::Booking(string customerName, string flightId, int seatNumber)
{
    static int Id = 100;
    Booking::Id = Id;
    Id++;
    Booking::customerName = customerName;
    Booking::flightId = flightId;
    Booking::seatNumber = seatNumber;
}

//---------------------------Setter Method of Booking Class ------------------
void Booking::setCustomerName(string customerName)
{
    Booking::customerName = customerName;
}

void Booking::setFlightId(string flightId)
{
    Booking::flightId = flightId;
}

void Booking::setSeatNumber(int seatNumber)
{
    Booking::seatNumber = seatNumber;
}

//---------------------------Getter Method of Booking Class ------------------
int Booking::getId() const
{
    return Booking::Id;
}
string Booking::getCustomerName() const
{
    return Booking::customerName;
}
string Booking::getFlightId() const
{
    return Booking::flightId;
}
int Booking::getSeatNumber() const
{
    return Booking::seatNumber;
}

//--------------------------- Airline Class ------------------
class Airline
{
    private:
        enum State
        {
            ADD_FLIGHT = 1,
            REMOVE_FLIGHT,
            SEARCH_FLIGHT,
            GET_FLIGHT_DETAIL,
            BOOK_FLIGHT,
            CANCEL_BOOKING,
            VIEW_BOOKING
        }state;
        vector<Flight> flightList;
        vector<Booking> bookingList;
        void showInfoFlight(Flight Flight);
        void showDetailFlight(Flight Flight);
    public:
        Airline();
        void addFlight(Flight Flight);
        void removeFlight(string flightId);
        void searchFlight(string Origin, string Destination);
        void getFlightDetail(string flightId);
        void bookFlight(string customerName, string flightId, int seatNumber);
        void cancelBooking(int bookingId);
        void viewBooking(string customerName);
};

//--------------------------- Constructor of Airline Class ------------------
Airline::Airline()
{
    while (true)
    {
        printf("\t\t\t* Welcome to ABC Airline *\n");
        printf("1. Add Flight\n");
        printf("2. Remove Flight\n");
        printf("3. Search Flight\n");
        printf("4. Get Flight Detail\n");
        printf("5. Book Flight\n");
        printf("6. Cancel Flight\n");
        printf("7. View Booking\n");
        printf("Enter your choice: ");
        int state = 0;
        scanf("%d", &state);

        switch (state)
        {
            char key;            // Use one key for all case
            case ADD_FLIGHT:
            {   
                printf("----------- ADD FLIGHT -------------\n");
                string tempOrigin;
                string tempDestination;
                time tempDepartureTime = {9,9};
                time tempArrivalTime = {9,9};
                int tempAvailableSeat;
                do
                {
                    printf("Enter Origin: ");
                    scanf("\n");
                    getline(cin,tempOrigin);

                    printf("Enter Destination: ");
                    getline(cin,tempDestination);

                    printf("Enter DepartureTime: \n");              
                    printf("Hour: ");
                    scanf("%d", &(tempDepartureTime.hour));
                    printf("Minute: ");
                    scanf("%d", &(tempDepartureTime.minute));

                    printf("Enter ArrivalTime: \n");
                    printf("Hour: ");
                    scanf("%d", &(tempArrivalTime.hour));
                    printf("Minute: ");
                    scanf("%d", &(tempArrivalTime.minute));

                    printf("Enter AvailableSeat: ");  
                    scanf("%d", &tempAvailableSeat);
                                
                    Flight newFlight(tempOrigin,tempDestination,tempDepartureTime,tempArrivalTime,tempAvailableSeat);     
                    Airline::addFlight(newFlight);

                    printf("Do you want to add another flight? (y/n): ");
                    scanf(" %c",&key);
                } while (key == 'y');           
                break;
            }
            case REMOVE_FLIGHT:
            {
                printf("---------- REMOVE FLIGHT ----------\n");
                string tempFlightId;
                do
                {
                    printf("Enter Flight ID: ");
                    scanf("\n");
                    getline(cin,tempFlightId);
                    Airline::removeFlight(tempFlightId);

                    printf("Do you want to remove another flight? (y/n): ");
                    scanf(" %c",&key);
                } while (key == 'y');
                
                break;
            }
            case SEARCH_FLIGHT:
            {
                printf("----------- SEARCH FLIGHT ---------- \n");
                string tempOrigin;
                string tempDestination;
                do
                {
                    printf("Enter Origin: ");
                    scanf("\n");
                    getline(cin,tempOrigin);

                    
                    printf("Enter Destination: ");
                    getline(cin,tempDestination);

                    searchFlight(tempOrigin, tempDestination);
                    
                    printf("Do you want to search another flight? (y/n): ");
                    scanf(" %c",&key);
                } while (key == 'y');
                break;
            }
            case GET_FLIGHT_DETAIL:
            {
                printf("---------- GET FLIGHT DETAIL ---------\n");
                string tempFlightId;
                do
                {
                    printf("Enter Flight ID: ");
                    scanf("\n");
                    getline(cin,tempFlightId);
                    Airline::getFlightDetail(tempFlightId);
                    
                    printf("Do you want to get another flight detail? (y/n): ");
                    scanf(" %c",&key);
                } while (key == 'y');
                break;
            }
            case BOOK_FLIGHT:
            {
                printf("---------- BOOK FLIGHT ---------\n");
                string tempCustomerName;
                string tempFlightId;
                int tempSeatNumber;
                do
                {
                    printf("Enter Your Name: ");
                    scanf("\n");
                    getline(cin,tempCustomerName);

                    printf("Enter Flight ID: ");
                    getline(cin,tempFlightId);

                    printf("Enter Seat Number: ");
                    scanf("%d", &tempSeatNumber);
                    
                    Airline::bookFlight(tempCustomerName, tempFlightId, tempSeatNumber);
                    printf("Do you want to book another flight? (y/n): ");
                    scanf(" %c",&key);
                } while (key == 'y');
                break;
            }
            case CANCEL_BOOKING:
            {
                printf("---------- CANCEL BOOKING ---------\n");
                int tempBookingId;
                do
                {
                    printf("Enter Booking ID: ");
                    scanf("\n");
                    scanf("%d", &tempBookingId);
                    cancelBooking(tempBookingId);

                    printf("Do you want to cancel another booking? (y/n): ");
                    scanf(" %c",&key);
                } while (key == 'y');  
            }
            case VIEW_BOOKING:
            {
                printf("---------- CANCEL BOOKING ---------\n");
                string tempCustomerName;

                do
                {
                    printf("Enter Your Name: ");
                    scanf("\n");
                    getline(cin,tempCustomerName);
                    Airline::viewBooking(tempCustomerName);
                    printf("Do you want to view another booking? (y/n): ");
                    scanf(" %c",&key);   
                } while (key == 'y');
                
            }
        default:
            printf("Invalid input, please try again.\n");
            continue;
        }
    }
    
}
//------------- Show Information of Flight Method of Airline Class ------------------
void Airline::showInfoFlight(Flight Flight)
{
    printf("Flight ID: %s | From: %s | To: %s\n", Flight.getId().c_str(), Flight.getOrigin().c_str(), Flight.getDestination().c_str());
    printf("Departure Time: %d:%d | Arrival Time: %d:%d\n\n",Flight.getDepartureTime().hour,Flight.getDepartureTime().minute, Flight.getArrivalTime().hour, Flight.getArrivalTime().minute);
}
//------------- Show Flight Detail Method of Airline Class ------------------
void showDetailFlight(Flight Flight)
{
    printf("Flight ID: %s | From: %s | To: %s\n", Flight.getId().c_str(), Flight.getOrigin().c_str(), Flight.getDestination().c_str());
    printf("Departure Time: %d:%d | Arrival Time: %d:%d |\n",Flight.getDepartureTime().hour,Flight.getDepartureTime().minute, Flight.getArrivalTime().hour, Flight.getArrivalTime().minute);
    printf("Available Seat: %d\n\n", Flight.getAvailableSeat());
}

//------------- Add Flight Method of Airline Class ------------------
void Airline::addFlight(Flight Flight)
{
    
    flightList.push_back(Flight);
}

void Airline::removeFlight(string flightId)
{
    uint8_t check = 1;
    for(int i = 0; i < flightList.size(); i++)
    {
        if(flightList[i].getId() == flightId)
        {
            check = 2;
            flightList.erase(flightList.begin() + i);
            break;
        }
    }
    if(check = 1) printf("No flight found!\n\n");
}
//------------- Search Flight Method of Airline Class ------------------
void Airline::searchFlight(string Origin, string Destination)
{
    uint8_t check = 1;
    for(auto flight: flightList)
    {
        if(flight.getOrigin() == Origin && flight.getDestination() == Destination)
        {
            check = 2;
            showInfoFlight(flight);
        }
    }
    if(check == 1) printf("No flight found!\n\n");
}
//------------- Get Flight Detail Method of Airline Class ------------------
void Airline::getFlightDetail(string flightId)
{
    uint8_t check = 1;
    for(auto flight: flightList)
    {
        if(flight.getId() == flightId)
        {
            check = 2;
            showDetailFlight(flight);
            break;
        }
    }
    if(check == 1) printf("No flight found!\n\n");
}
//------------- Book Flight Method of Airline Class ------------------
void Airline::bookFlight(string customerName, string flightId, int seatNumber)
{
    uint8_t check = 1;
    Booking newBooking(customerName,flightId,seatNumber);
    for(auto& flight : flightList)
    {
        if(flight.getId() == flightId) //Check exist flight ID
        {
            check = 2;
            if(flight.getAvailableSeat() > 0) //Check available seat
            {
                if(bookingList.size() == 0)
                {
                    flight.setAvailableSeat(flight.getAvailableSeat() - 1);
                    bookingList.push_back(newBooking);
                    printf("Booking Successful!\n\n");
                    break;
                }
                else
                {
                    for(auto booking : bookingList) 
                    {
                        if(booking.getFlightId() == flightId)
                        {
                            if(booking.getSeatNumber() == seatNumber) // check same seat number
                            {
                                printf("That seat has been booked. Please chose another seat or flight!\n\n");
                                break; 
                            }              
                        }
                        flight.setAvailableSeat(flight.getAvailableSeat() - 1);
                        bookingList.push_back(newBooking);
                        printf("Booking Successful!\n\n");
                        break;
                    }      
                }
            }
            else printf("Sorry, there are no more available seats on this flight. Please chose another flight\n\n");
            break;
        }
    }
    if(check == 1) printf("No fight found with Flight ID: %s", flightId.c_str());
}
//------------- Cancel Booking Method of Airline Class ------------------
void Airline::cancelBooking(int bookingId)
{
    string tempFlightId;
    uint8_t check = 1;
    for(int i = 0; i < bookingList.size(); i++)
    {
        if(bookingList[i].getId() == bookingId)
        {
            check = 2;
            tempFlightId = bookingList[i].getFlightId();
            bookingList.erase(bookingList.begin() + i);
            break;
        }
    }
    if(check == 1)
    {
        printf("No booking found!\n\n");
    }
    else
    {
        for(auto flight : flightList)
        {
            if(flight.getId() == tempFlightId)
            {
                flight.setAvailableSeat(flight.getAvailableSeat() + 1);
            }
        }
        printf("Canceling Booking Successful!\n\n");
    }
}
//------------- View Booking Method of Airline Class ------------------
void Airline::viewBooking(string customerName)
{
    uint8_t check = 1;
    for(auto booking : bookingList)
    {
        if(booking.getCustomerName() == customerName)
        {
            check = 2;
            printf("Customer Name: %s\n", booking.getCustomerName().c_str());
            printf("Flight ID: %s\n", booking.getFlightId().c_str());
            printf("Seat Number: %d\n", booking.getSeatNumber());
            break;
        }
    }
    if(check == 1) printf("No booking found!\n\n");
}
//====================== MAIN =====================
int main(int argc, char const *argv[])
{
    Airline al;
    return 0;
}
