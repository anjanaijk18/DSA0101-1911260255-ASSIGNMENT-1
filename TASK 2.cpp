TASK 2 – Use Tokens, Keywords, Identifiers and Constants Correctly

1. Aim
  
To define the metro fares, peak surcharge and minimum balance in one place using appropriate C++ constants and an `enum class`, so that future changes can be made easily and consistently.

2. C++ Program
  
#include <iostream>
using namespace std;

constexpr long long INNER_FARE_PAISE = 1000;
constexpr long long MIDDLE_FARE_PAISE = 2000;
constexpr long long OUTER_FARE_PAISE = 3000;

constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;
enum class Zone {
    Inner,
    Middle,
    Outer
};

long long calculateFare(Zone zone, bool isPeak) {
    long long fare = 0;

    switch (zone) {
        case Zone::Inner:
            fare = INNER_FARE_PAISE;
            break;

        case Zone::Middle:
            fare = MIDDLE_FARE_PAISE;
            break;

        case Zone::Outer:
            fare = OUTER_FARE_PAISE;
            break;
    }

    if (isPeak) {
        fare += fare * PEAK_SURCHARGE_PERCENT / 100;
    }

    return fare;
}

bool canTravel(long long balance, long long fare) {
    return balance - fare >= MIN_BALANCE_PAISE;
}

int main() {
    cout << "Inner fare: "
         << calculateFare(Zone::Inner, false) << " paise\n";

    cout << "Middle fare during peak: "
         << calculateFare(Zone::Middle, true) << " paise\n";

    cout << "Outer fare during peak: "
         << calculateFare(Zone::Outer, true) << " paise\n";

    cout << "Minimum balance: "
         << MIN_BALANCE_PAISE << " paise\n";

    return 0;
}
OUTPUT:
Inner fare: 1000 paise
Middle fare during peak: 2400 paise
Outer fare during peak: 3600 paise
Minimum balance: 5000 paise
