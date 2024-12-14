#include <iostream>
#include <string>

using namespace std;

class Concert{
private:
    string concertName;
    int totalSeats;
    bool* seats;
    static int totalBookedSeats;

public:

    Concert(string name, int totalSeats)
      {
        concertName=name;
        this->totalSeats=totalSeats;
        seats = new bool[totalSeats];
        for (int i = 0; i < totalSeats; i++)
        {
            seats[i]=false;
        }
    }
    bool bookSeat(int seatNumber)
     {
        if (seatNumber<1||seatNumber>totalSeats)
        {
            cout<<"Invalid seat number. Please enter a seat number between 1 and "<<totalSeats<<endl;
            return false;
        }
        if (seats[seatNumber-1])
        {
            cout<<"Seat "<<seatNumber << " is already booked."<<endl;
            return false;
        }
        seats[seatNumber-1]=true;
        totalBookedSeats++;
        cout<<"Seat "<<seatNumber<<" has been successfully booked."<<endl;
        return true;
    }
    bool cancelBooking(int seatNumber)
    {
        if (seatNumber<1||seatNumber>totalSeats)
        {
            cout<<"Invalid seat number.Please enter a seat number between 1 and "<<totalSeats<<endl;
            return false;
        }
        if (!seats[seatNumber-1])
        {
            cout<<"Seat "<<seatNumber<<" is not booked."<<endl;
            return false;
        }
        seats[seatNumber-1]=false;
        totalBookedSeats--;
        cout<<"Booking for seat "<<seatNumber<< " has been successfully canceled."<<endl;
        return true;
    }

    void checkSeatAvailability() const{
        cout<<"Seat availability for "<<concertName<<endl;
        for (int i = 0; i < totalSeats; i++)
        {
            cout<<"Seat "<<(i + 1) <<":"<<(seats[i]==true?"Booked":"Available") <<endl;
        }
    }

    static int getTotalBookedSeats()
    {
        return totalBookedSeats;
    }
};

int Concert::totalBookedSeats = 0;

int main() {

    Concert concert1("Tahsan",5);
    Concert concert2("Atif Aslam",3);

    concert1.bookSeat(1);
    concert1.bookSeat(3);
    concert2.bookSeat(2);

    concert1.checkSeatAvailability();
    concert2.checkSeatAvailability();

    concert1.cancelBooking(3);

    concert1.checkSeatAvailability();

    cout << "Total seats booked across all concerts: "<<Concert::getTotalBookedSeats()<<endl;

    return 0;
}
