#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main() {
    int zone, hour;
    long long balance;

    cout << "Enter zone (1=Inner, 2=Middle, 3=Outer): ";
    while (!(cin >> zone) || zone < 1 || zone > 3) {
        cout << "Invalid zone. Enter 1, 2 or 3: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter hour (0-23): ";
    while (!(cin >> hour) || hour < 0 || hour > 23) {
        cout << "Invalid hour. Enter 0-23: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter card balance in paise: ";
    while (!(cin >> balance) || balance < 0) {
        cout << "Invalid balance. Enter a non-negative amount: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

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
    }

    bool peak = (hour >= 8 && hour < 10) ||
                (hour >= 17 && hour < 20);

    if (peak) {
        fare += fare * 20 / 100;
    }

    cout << fixed << setprecision(2);

    cout << "\n----- METRO JOURNEY REPORT -----\n";
    cout << "Zone: " << zone << '\n';
    cout << "Hour: " << hour << ":00\n";
    cout << "Peak hour: " << boolalpha << peak << '\n';

    cout << "Fare: Rs "
         << static_cast<double>(fare) / 100.0 << '\n';

    if (balance >= fare && balance - fare >= 5000) {
        balance -= fare;
        cout << "Journey status: Approved\n";
    } else {
        cout << "Journey status: Denied\n";
    }

    cout << "Remaining balance: Rs "
         << static_cast<double>(balance) / 100.0 << '\n';

    return 0;
} 

SAMPLE INPUT:
1
8
10000

OUTPUT:
Enter zone (1=Inner, 2=Middle, 3=Outer): 1
Enter hour (0-23): 8
Enter card balance in paise: 10000

----- METRO JOURNEY REPORT -----
Zone: 1
Hour: 8:00
Peak hour: true
Fare: Rs 12.00
Journey status: Approved
Remaining balance: Rs 88.00
