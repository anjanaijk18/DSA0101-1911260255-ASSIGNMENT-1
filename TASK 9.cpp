#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

constexpr long long MIN_BALANCE = 5000;
constexpr int SURCHARGE_PERCENT = 20;

enum class Zone {
    Inner = 1,
    Middle = 2,
    Outer = 3
};

bool isPeak(int hour) {
    return (hour >= 8 && hour < 10) ||
           (hour >= 17 && hour < 20);
}

bool getFare(int zone, int hour, long long& fare) {
    if (hour < 0 || hour > 23 ||
        zone < 1 || zone > 3) {
        return false;
    }

    switch (static_cast<Zone>(zone)) {
        case Zone::Inner:
            fare = 1000;
            break;
        case Zone::Middle:
            fare = 2000;
            break;
        case Zone::Outer:
            fare = 3000;
            break;
        default:
            return false;
    }

    if (isPeak(hour)) {
        fare += fare * SURCHARGE_PERCENT / 100;
    }

    return true;
}

bool canTravel(long long balance, long long fare) {
    return fare >= 0 &&
           balance >= fare &&
           balance - fare >= MIN_BALANCE;
}

void testCase(string name, int zone, int hour,
              long long balance) {
    long long fare = 0;

    cout << left << setw(28) << name;

    if (!getFare(zone, hour, fare)) {
        cout << "Invalid input\n";
        return;
    }

    cout << "Fare Rs "
         << fare / 100 << '.'
         << setw(2) << setfill('0') << fare % 100
         << setfill(' ');

    if (canTravel(balance, fare)) {
        cout << " | Approved | Balance Rs "
             << (balance - fare) / 100 << '.'
             << setw(2) << setfill('0')
             << (balance - fare) % 100
             << setfill(' ');
    } else {
        cout << " | Denied (minimum balance rule)";
    }

    cout << '\n';
}

int main() {
    cout << "METRO FARE TEST REPORT\n\n";

    // Normal zone fares: off-peak and peak
    testCase("Inner off-peak", 1, 11, 10000);
    testCase("Middle off-peak", 2, 11, 10000);
    testCase("Outer off-peak", 3, 11, 10000);
    testCase("Inner peak", 1, 8, 10000);
    testCase("Middle peak", 2, 8, 10000);
    testCase("Outer peak", 3, 8, 10000);

    cout << "\nBoundary tests\n";
    testCase("Exactly 8:00", 1, 8, 10000);
    testCase("Exactly 10:00", 1, 10, 10000);
    testCase("Exactly 17:00", 1, 17, 10000);
    testCase("Exactly 20:00", 1, 20, 10000);

    // Rs 62 balance - Rs 12 peak fare = Rs 50
    testCase("Leaves exactly Rs 50", 1, 8, 6200);

    cout << "\nInvalid tests\n";
    testCase("Unknown zone", 4, 11, 10000);
    testCase("Invalid hour", 1, 25, 10000);

    cout << "\nFive-journey calculation\n";

    long long balance = 100000;
    long long totalFare = 0;

    int zones[] = {1, 2, 3, 1, 2};
    int hours[] = {11, 8, 18, 20, 12};

    for (int i = 0; i < 5; ++i) {
        long long fare = 0;

        if (getFare(zones[i], hours[i], fare) &&
            canTravel(balance, fare)) {
            balance -= fare;
            totalFare += fare;

            cout << "Journey " << i + 1
                 << ": Rs " << fare / 100 << '.'
                 << setw(2) << setfill('0') << fare % 100
                 << setfill(' ') << '\n';
        }
    }
cout << "Total fare: Rs "
         << totalFare / 100 << '.'
         << setw(2) << setfill('0') << totalFare % 100
         << setfill(' ') << '\n';

    cout << "Final balance: Rs "
         << balance / 100 << '.'
         << setw(2) << setfill('0') << balance % 100
         << setfill(' ') << '\n';

    return 0;
}

OUTPUT:
METRO FARE TEST REPORT

Inner off-peak             Fare Rs 10.00 | Approved | Balance Rs 90.00
Middle off-peak            Fare Rs 20.00 | Approved | Balance Rs 80.00
Outer off-peak             Fare Rs 30.00 | Approved | Balance Rs 70.00
Inner peak                  Fare Rs 12.00 | Approved | Balance Rs 88.00
Middle peak                 Fare Rs 24.00 | Approved | Balance Rs 76.00
Outer peak                  Fare Rs 36.00 | Approved | Balance Rs 64.00

Boundary tests
Exactly 8:00                Fare Rs 12.00 | Approved | Balance Rs 88.00
Exactly 10:00               Fare Rs 10.00 | Approved | Balance Rs 90.00
Exactly 17:00               Fare Rs 12.00 | Approved | Balance Rs 88.00
Exactly 20:00               Fare Rs 10.00 | Approved | Balance Rs 90.00
Leaves exactly Rs 50        Fare Rs 12.00 | Approved | Balance Rs 50.00

Invalid tests
Unknown zone                Invalid input
Invalid hour                Invalid input

Five-journey calculation
Journey 1: Rs 10.00
Journey 2: Rs 24.00
Journey 3: Rs 36.00
Journey 4: Rs 10.00
Journey 5: Rs 20.00
Total fare: Rs 100.00
Final balance: Rs 900.00
