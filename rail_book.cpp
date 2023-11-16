#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Train {
private:
    string trainName;
    string source;
    string destination;
    int totalSeats;
    int availableSeats;

public:
    Train(string name, string src, string dest, int seats) {
        trainName = name;
        source = src;
        destination = dest;
        totalSeats = seats;
        availableSeats = seats;
    }

    string getTrainName() const {
        return trainName;
    }

    string getSource() const {
        return source;
    }

    string getDestination() const {
        return destination;
    }

    int getAvailableSeats() const {
        return availableSeats;
    }

    void bookSeats(int numSeats) {
        if (numSeats <= availableSeats) {
            availableSeats -= numSeats;
            cout << "Tickets booked successfully!" << endl;
        } else {
            cout << "Sorry, insufficient seats available." << endl;
        }
    }
};

class Ticket {
private:
    string passengerName;
    Train train;
    int numSeats;

public:
    Ticket(string name, const Train& t, int seats) : passengerName(name), train(t), numSeats(seats) {}

    void displayTicketDetails() const {
        cout << "Passenger Name: " << passengerName << endl;
        cout << "Train Name: " << train.getTrainName() << endl;
        cout << "Source: " << train.getSource() << " Destination: " << train.getDestination() << endl;
        cout << "Number of Seats: " << numSeats << endl;
    }
};

int main() {
    vector<Train> trains;
    trains.push_back(Train("Express 1", "New York", "Chicago", 100));
    trains.push_back(Train("Superfast 2", "Los Angeles", "San Francisco", 150));

    vector<Ticket> tickets;
    char choice;

    do {
        cout << "Select a train:" << endl;
        for (size_t i = 0; i < trains.size(); ++i) {
            cout << i + 1 << ". " << trains[i].getTrainName() << " from "
                 << trains[i].getSource() << " to " << trains[i].getDestination()
                 << " (" << trains[i].getAvailableSeats() << " seats available)" << endl;
        }

        int trainChoice;
        cout << "Enter train number: ";
        cin >> trainChoice;
        cin.ignore();

        if (trainChoice >= 1 && trainChoice <= trains.size()) {
            int numPassengers;
            cout << "Enter number of passengers: ";
            cin >> numPassengers;
            cin.ignore();

            Train& selectedTrain = trains[trainChoice - 1];
            selectedTrain.bookSeats(numPassengers);

            if (selectedTrain.getAvailableSeats() >= numPassengers) {
                string passengerName;
                cout << "Enter passenger name: ";
                getline(cin, passengerName);

                tickets.push_back(Ticket(passengerName, selectedTrain, numPassengers));
            }
        } else {
            cout << "Invalid choice!" << endl;
        }

        cout << "Do you want to book another ticket? (y/n): ";
        cin >> choice;
        cin.ignore();
    } while (choice == 'y' || choice == 'Y');

    cout << "\n--- Ticket Details ---\n";
    for (const Ticket& ticket : tickets) {
        ticket.displayTicketDetails();
        cout << "---------------------------" << endl;
    }

    return 0;
}
