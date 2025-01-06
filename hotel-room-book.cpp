#include <iostream>
#include <string>

using namespace std;

class HotelRoom {
private:
    int roomID;
    string roomType;
    bool occupancy[30];

public:
    HotelRoom(int id, string type) : roomID(id), roomType(type) {
        for (int i = 0; i < 30; ++i) {
            occupancy[i] = false;
        }
    }

    int getRoomID() const {
        return roomID;
    }

    string getRoomType() const {
        return roomType;
    }

    bool checkIn(int startDate, int endDate) {
        if (startDate < 0 || startDate > 29 || endDate < 0 || endDate > 29 || startDate > endDate) {
            cout << "Invalid date range." << endl;
            return false;
        }

        for (int i = startDate; i <= endDate; ++i) {
            if (occupancy[i]) {
                cout << "Room already booked for some dates." << endl;
                return false;
            }
            occupancy[i] = true;
        }

        return true;
    }

    bool checkOut(int startDate, int endDate) {
        if (startDate < 0 || startDate > 29 || endDate < 0 || endDate > 29 || startDate > endDate) {
            cout << "Invalid date range." << endl;
            return false;
        }

        for (int i = startDate; i <= endDate; ++i) {
            occupancy[i] = false;
        }

        return true;
    }

    void viewAvailability() {
        cout << "Room ID: " << roomID << ", Room Type: " << roomType << endl;
        cout << "Availability:" << endl;
        for (int i = 0; i < 30; ++i) {
            if (!occupancy[i]) {
                cout << i + 1 << " ";
            }
        }
        cout << endl;
    }

    static double calculateOccupancyRate(HotelRoom* rooms[], int numRooms) {
        int totalDays = 30 * numRooms;
        int occupiedDays = 0;

        for (int i = 0; i < numRooms; ++i) {
            for (int j = 0; j < 30; ++j) {
                if (rooms[i]->occupancy[j]) {
                    occupiedDays++;
                }
            }
        }

        return (double)occupiedDays / totalDays;
    }
};

class LuxuryRoom : public HotelRoom {
private:
    string* amenities;
    int numAmenities;

public:
    LuxuryRoom(int id, string type, string* amenities, int numAmenities)
        : HotelRoom(id, type), amenities(amenities), numAmenities(numAmenities) {}

    void viewAvailability()  {
        HotelRoom::viewAvailability();
        cout << "Amenities:" << endl;
        for (int i = 0; i < numAmenities; ++i) {
            cout << "- " << amenities[i] << endl;
        }
    }
};

int main() {
    HotelRoom* rooms[3];
    rooms[0] = new HotelRoom(101, "Single");
    rooms[1] = new HotelRoom(102, "Double");
    string luxuryAmenities[] = {"Ocean View", "Spa Access"};
    rooms[2] = new LuxuryRoom(103, "Suite", luxuryAmenities, 2);

    rooms[0]->checkIn(1, 5);
    rooms[1]->checkIn(10, 15);
    rooms[2]->checkIn(20, 25);

    rooms[0]->checkOut(3, 4);

    rooms[0]->viewAvailability();
    rooms[1]->viewAvailability();
    rooms[2]->viewAvailability();

    double occupancyRate = HotelRoom::calculateOccupancyRate(rooms, 3);
    cout << "Overall Occupancy Rate: " << occupancyRate << endl;


    for (int i = 0; i < 3; ++i) {
        delete rooms[i];
    }

    return 0;
}
