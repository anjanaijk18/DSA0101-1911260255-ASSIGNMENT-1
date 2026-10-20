#include <iostream> #include <iomanip> #include <array> using namespace std;
enum class Zone { Inner, Middle, Outer, Airport };

constexpr array<long long, 4> BASE_FARE = {
1000, 2000, 3000, 6000
};

constexpr long long MIN_BALANCE = 5000;

class Pass {
private:
bool active;
Zone zone1, zone2;

public:
Pass(bool status, Zone first, Zone second)
: active(status), zone1(first), zone2(second) {}

bool covers(Zone z) const {
    return active && (z == zone1 || z == zone2);
}
};

class SmartCard {
private:
long long balance;

public:
SmartCard(long long initialBalance) : balance(initialBalance) {}

bool canTravel(long long fare) const {
    return balance - fare >= MIN_BALANCE;
}

bool deduct(long long fare) {
    if (!canTravel(fare))
        return false;

    balance -= fare;
    return true;
}

long long getBalance() const {
    return balance;
}
};

long long calculateFare(Zone zone, int hour, bool weekend) {
int index = static_cast<int>(zone);
long long fare = BASE_FARE[index];

bool peak = (hour >= 8 && hour < 10) ||
            (hour >= 17 && hour < 20);

if (weekend) {
    fare = fare * 90 / 100;
} else if (peak) {
    fare = fare * 120 / 100;
}

return fare;
}

void printMoney(long long paise) {
cout << "Rs " << paise / 100 << '.'
<< setw(2) << setfill('0') << paise % 100
<< setfill(' ');
}

int main() {
SmartCard card(20000);

Pass monthlyPass(true, Zone::Inner, Zone::Middle);

struct Trip {
    Zone zone;
    int hour;
    bool weekend;
};

Trip trips[] = {
    {Zone::Inner, 9, false},
    {Zone::Outer, 18, false},
    {Zone::Airport, 12, false},
    {Zone::Airport, 12, true},
    {Zone::Middle, 14, false}
};

cout << "Task 12: Revised Metro Fare System\n";

for (const Trip& trip : trips) {
    cout << "Zone: ";

    switch (trip.zone) {
        case Zone::Inner: cout << "Inner"; break;
        case Zone::Middle: cout << "Middle"; break;
        case Zone::Outer: cout << "Outer"; break;
        case Zone::Airport: cout << "Airport"; break;
    }

    if (monthlyPass.covers(trip.zone)) {
        cout << " - Monthly pass: Rs 0.00";
    } else {
        long long fare = calculateFare(
            trip.zone, trip.hour, trip.weekend
        );

        cout << " - Fare: ";
        printMoney(fare);

        if (!card.deduct(fare))
            cout << " - Journey denied (minimum balance rule)";
    }

    cout << " - Balance: ";
    printMoney(card.getBalance());
    cout << '\n';
}

return 0;
}
OUTPUT:
### C++ Code — Task 12

<CodeBlock language="cpp" editable>
#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

enum class Zone { Inner, Middle, Outer, Airport };

constexpr array<long long, 4> BASE_FARE = {
    1000, 2000, 3000, 6000
};

constexpr long long MIN_BALANCE = 5000;

class Pass {
private:
    bool active;
    Zone zone1, zone2;

public:
    Pass(bool status, Zone first, Zone second)
        : active(status), zone1(first), zone2(second) {}

    bool covers(Zone z) const {
        return active && (z == zone1 || z == zone2);
    }
};

class SmartCard {
private:
    long long balance;

public:
    SmartCard(long long initialBalance) : balance(initialBalance) {}

    bool canTravel(long long fare) const {
        return balance - fare >= MIN_BALANCE;
    }

    bool deduct(long long fare) {
        if (!canTravel(fare))
            return false;

        balance -= fare;
        return true;
    }

    long long getBalance() const {
        return balance;
    }
};

long long calculateFare(Zone zone, int hour, bool weekend) {
    int index = static_cast<int>(zone);
    long long fare = BASE_FARE[index];

    bool peak = (hour >= 8 && hour < 10) ||
                (hour >= 17 && hour < 20);

    if (weekend) {
        fare = fare * 90 / 100;
    } else if (peak) {
        fare = fare * 120 / 100;
    }

    return fare;
}

void printMoney(long long paise) {
    cout << "Rs " << paise / 100 << '.'
         << setw(2) << setfill('0') << paise % 100
         << setfill(' ');
}

int main() {
    SmartCard card(20000);

    Pass monthlyPass(true, Zone::Inner, Zone::Middle);

    struct Trip {
        Zone zone;
        int hour;
        bool weekend;
    };

    Trip trips[] = {
        {Zone::Inner, 9, false},
        {Zone::Outer, 18, false},
        {Zone::Airport, 12, false},
        {Zone::Airport, 12, true},
        {Zone::Middle, 14, false}
    };

    cout << "Task 12: Revised Metro Fare System\n";

    for (const Trip& trip : trips) {
        cout << "Zone: ";

        switch (trip.zone) {
            case Zone::Inner: cout << "Inner"; break;
            case Zone::Middle: cout << "Middle"; break;
            case Zone::Outer: cout << "Outer"; break;
            case Zone::Airport: cout << "Airport"; break;
        }

        if (monthlyPass.covers(trip.zone)) {
            cout << " - Monthly pass: Rs 0.00";
        } else {
            long long fare = calculateFare(
                trip.zone, trip.hour, trip.weekend
            );

            cout << " - Fare: ";
            printMoney(fare);

            if (!card.deduct(fare))
                cout << " - Journey denied (minimum balance rule)";
        }

        cout << " - Balance: ";
        printMoney(card.getBalance());
        cout << '\n';
    }

    return 0;
}

OUTPUT:
Task 12: Revised Metro Fare System
Zone: Inner - Monthly pass: Rs 0.00 - Balance: Rs 200.00
Zone: Outer - Fare: Rs 36.00 - Balance: Rs 164.00
Zone: Airport - Fare: Rs 60.00 - Balance: Rs 104.00
Zone: Airport - Fare: Rs 54.00 - Balance: Rs 50.00
Zone: Middle - Monthly pass: Rs 0.00 - Balance: Rs 50.00
