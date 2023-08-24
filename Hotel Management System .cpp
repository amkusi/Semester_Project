#include <iostream>
#include <vector>
#include <string>

class Guest {
public:
    Guest(const std::string& name, int roomNumber)
        : name(name), roomNumber(roomNumber) {}

    std::string getName() const { return name; }
    int getRoomNumber() const { return roomNumber; }

private:
    std::string name;
    int roomNumber;
};

class Hotel {
public:
    Hotel(const std::string& name, int maxRooms)
        : name(name), maxRooms(maxRooms) {
        rooms.reserve(maxRooms);
    }

    bool checkIn(const std::string& guestName, int roomNumber) {
        if (roomNumber < 1 || roomNumber > maxRooms) {
            std::cout << "Invalid room number!" << std::endl;
            return false;
        }

        for (const Guest& guest : rooms) {
            if (guest.getRoomNumber() == roomNumber) {
                std::cout << "Room already occupied!" << std::endl;
                return false;
            }
        }

        rooms.push_back(Guest(guestName, roomNumber));
        std::cout << "Check-in successful!" << std::endl;
        return true;
    }

    void checkOut(int roomNumber) {
        for (size_t i = 0; i < rooms.size(); ++i) {
            if (rooms[i].getRoomNumber() == roomNumber) {
                rooms.erase(rooms.begin() + i);
                std::cout << "Check-out successful!" << std::endl;
                return;
            }
        }
        std::cout << "Room not found or already vacant!" << std::endl;
    }

private:
    std::string name;
    int maxRooms;
    std::vector<Guest> rooms;
};

int main() {
    Hotel hotel("Example Hotel", 10);

    while (true) {
        std::cout << "1. Check-in\n2. Check-out\n3. Quit\n";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::string guestName;
            int roomNumber;
            std::cout << "Enter guest name: ";
            std::cin >> guestName;
            std::cout << "Enter room number: ";
            std::cin >> roomNumber;
            hotel.checkIn(guestName, roomNumber);
        } else if (choice == 2) {
            int roomNumber;
            std::cout << "Enter room number: ";
            std::cin >> roomNumber;
            hotel.checkOut(roomNumber);
        } else if (choice == 3) {
            break;
        } else {
            std::cout << "Invalid choice. Try again.\n";
        }
    }

return 0;
}
