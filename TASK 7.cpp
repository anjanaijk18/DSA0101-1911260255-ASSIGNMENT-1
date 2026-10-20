#include <iostream>
using namespace std;

constexpr long long MIN_BALANCE_PAISE = 5000;

// PROCEDURAL APPROACH

long long calculateFare(int zone, bool peak) {
    long long fare = 0;

    switch (zone) {
        case 1:
            fare = 1000;
            break;
        case 2:
            fare = 2000;
            break;
        case 3:
            fare = 3000;
            break;
        default:
            return -1;
    }

    if (peak) {
        fare += fare * 20 / 100;
    }

    return fare;
}

bool proceduralCanTravel(long long balance, long long fare) {
    return fare >= 0 &&
           balance >= fare &&
           balance - fare >= MIN_BALANCE_PAISE;
}

// OBJECT-ORIENTED APPROACH

class SmartCard {
private:
    long long balance;

public:
    SmartCard(long long initialBalance) {
        balance = initialBalance >= 0 ? initialBalance : 0;
    }

    bool canTravel(long long fare) const {
        return fare >= 0 &&
               balance >= fare &&
               balance - fare >= MIN_BALANCE_PAISE;
    }

    bool deduct(long long fare) {
        if (!canTravel(fare)) {
            return false;
        }

        balance -= fare;
        return true;
    }

    long long getBalance() const {
        return balance;
    }
};

int main() {
    // Procedural example
    long long proceduralBalance = 10000;
    long long fare = calculateFare(3, true);

    if (proceduralCanTravel(proceduralBalance, fare)) {
        proceduralBalance -= fare;
        cout << "Procedural fare: "
             << fare << " paise\n";
        cout << "Procedural balance: "
             << proceduralBalance << " paise\n";
    } else {
        cout << "Procedural journey denied\n";
    }

    // Object-oriented example
    SmartCard card(10000);
    long long objectFare = calculateFare(3, true);

    if (card.deduct(objectFare)) {
        cout << "OOP fare: "
             << objectFare << " paise\n";
        cout << "OOP balance: "
             << card.getBalance() << " paise\n";
    } else {
        cout << "OOP journey denied\n";
    }

    return 0;
}

OUTPUT:
Procedural fare: 3600 paise
Procedural balance: 6400 paise
OOP fare: 3600 paise
OOP balance: 6400 paise
