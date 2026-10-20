#include <climits>
#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

int main() {
    cout << "Sizes in bytes\n";
    cout << "bool: " << sizeof(bool) << '\n';
    cout << "char: " << sizeof(char) << '\n';
    cout << "int: " << sizeof(int) << '\n';
    cout << "unsigned int: " << sizeof(unsigned int) << '\n';
    cout << "long long: " << sizeof(long long) << '\n';
    cout << "float: " << sizeof(float) << '\n';
    cout << "double: " << sizeof(double) << '\n';

    cout << "\nInteger ranges\n";
    cout << "INT_MIN: " << INT_MIN << '\n';
    cout << "INT_MAX: " << INT_MAX << '\n';
    cout << "UINT_MAX: " << UINT_MAX << '\n';
    cout << "LLONG_MIN: " << LLONG_MIN << '\n';
    cout << "LLONG_MAX: " << LLONG_MAX << '\n';

    cout << "\nDaily collection analysis\n";

    const long long journeys = 3000000;
    const long long maximumFarePaise = 3600;
    const long long totalPaise =
        journeys * maximumFarePaise;

    cout << "Journeys: " << journeys << '\n';
    cout << "Maximum fare: " << maximumFarePaise
         << " paise\n";
    cout << "Total collection: " << totalPaise
         << " paise\n";
    cout << "Total in rupees: Rs "
         << totalPaise / 100 << '\n';

    cout << "\nDouble precision example\n";
    double amount = 0.0;

    for (int i = 0; i < 10; ++i) {
        amount += 0.1;
    }

    cout << setprecision(17);
    cout << "Ten additions of 0.1: " << amount << '\n';

    return 0;
}
OUTPUT:
Sizes in bytes
bool: 1
char: 1
int: 4
unsigned int: 4
long long: 8
float: 4
double: 8

Integer ranges
INT_MIN: -2147483648
INT_MAX: 2147483647
UINT_MAX: 4294967295
LLONG_MIN: -9223372036854775808
LLONG_MAX: 9223372036854775807

Daily collection analysis
Journeys: 3000000
Maximum fare: 3600 paise
Total collection: 10800000000 paise
Total in rupees: Rs 108000000

Double precision example
Ten additions of 0.1: 0.99999999999999989
