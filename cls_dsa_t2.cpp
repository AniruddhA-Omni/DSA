#include <iostream>
#include <stack>
using namespace std;

const int MAX_SEATS = 100;

class TicketSystem {
private:
  int seats[MAX_SEATS];
  stack<int> bookedSeats;
  int price = 0;

public:
  TicketSystem() {
    // initialize all seats as available
    for (int i = 0; i < MAX_SEATS; i++) {
      seats[i] = 0;
    }
    price = 100;
  }
  TicketSystem(int price) {
    // initialize all seats as available
    for (int i = 0; i < MAX_SEATS; i++) {
      seats[i] = 0;
    }
    this->price = price;
  }
  
  void displaySeats() {
    cout << "Seats: ";
    for (int i = 0; i < MAX_SEATS; i++) {
      cout << seats[i] << " ";
    }
    cout << endl;
  }

  void displayBookedSeats() {
    cout << "Booked seats: ";
    stack<int> temp = bookedSeats;
    while (!temp.empty()) {
      cout << temp.top() << " ";
      temp.pop();
    }
    cout << endl;
  }

  void editPrice(int price) {
    cout << "Old Price: " << this->price << endl;
    this->price = price;
    cout << "New Price: " << this->price << endl;
  }

  void bookTicket() {
    // check if any seats are available
    if (bookedSeats.size() == MAX_SEATS) {
      cout << "Sorry, all seats are booked." <<endl;
      return;
    }

    // find the first available seat
    int seat = -1;
    for (int i = 0; i < MAX_SEATS; i++) {
      if (seats[i] == 0) {
        seat = i;
        break;
      }
    }

    // book the seat
    bookedSeats.push(seat);
    seats[seat] = 1;

     cout << "Ticket booked! Your seat number is " << seat <<  endl;
  }

  void cancelTicket() {
    // check if there are any booked seats
    if (bookedSeats.empty()) {
       cout << "Sorry, there are no booked tickets." <<  endl;
      return;
    }

    // get the most recently booked seat
    int seat = bookedSeats.top();
    bookedSeats.pop();
    seats[seat] = 0;

     cout << "Ticket cancelled! Seat number " << seat << " is now available."
              <<  endl;
  }
};

int main() {
  TicketSystem ticketSystem;

  int choice, num;
  while (true) {
        cout<<  endl;
        cout << "Welcome to the ticket booking system!" <<  endl;
        cout << "Please select an option:" <<  endl;
        cout << "1. Edit ticket price" <<  endl;
        cout << "2. Display seats" <<  endl;
        cout << "3. Book a ticket" <<  endl;
        cout << "4. Cancel a ticket" <<  endl;
        cout << "5. Exit" <<  endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout<<  endl;
            cout << "Enter new ticket price: ";
            cin >> num;
            ticketSystem.editPrice(num);
            break;
        case 2:
            cout<<  endl;
            ticketSystem.displaySeats();
            ticketSystem.displayBookedSeats();
            break;
        case 3:
            cout<<  endl;
            ticketSystem.bookTicket();
            break;
        case 4:
            cout<<  endl;
            ticketSystem.cancelTicket();
            break;
        case 5:
            return 0;
            break;
        default:
            cout<<  endl;
            cout << "Invalid choice." <<  endl;
            break;
        }
    }

    return 0;
}
