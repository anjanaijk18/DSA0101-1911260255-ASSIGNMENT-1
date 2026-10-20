#include <climits>
#include <iomanip>
#include <iostream>
using namespace std;

void compareTotals(long long journeys) {
    const double fareRupees = 10.10;
    const long long farePaise = 1010;

    double doubleTotal = 0.0;
    long long paiseTotal = 0;

    for (long long i = 0; i < journeys; ++i) {
        doubleTotal += fareRupees;
        paiseTotal += farePaise;
    }

    double exactRupees = static_cast<double>(paiseTotal) / 100.0;

    cout << "\nJourneys: " << journeys << '\n';
    cout << "Double total: Rs "
         << setprecision(17) << doubleTotal << '\n';
    cout << "Integer-paise total: "
         << paiseTotal << " paise\n";
    cout << "Integer total in rupees: Rs "
         << fixed << setprecision(2) << exactRupees << '\n';
    cout << "Difference: Rs "
         << scientific << setprecision(10)
         << (doubleTotal - exactRupees) << '\n';

    cout << fixed << setprecision(2);
}

int main() {
    cout << "DOUBLE VS INTEGER-PAISE COMPARISON\n";

    compareTotals(20000);
    compareTotals(500000);
    compareTotals(3000000);

    cout << "\nINTEGER RANGE ANALYSIS\n";

    const long long journeys = 3000000;
    const long long farePaise = 3600;
    const long long networkTotal = journeys * farePaise;

    cout << "Maximum fare: " << farePaise << " paise\n";
    cout << "Journeys: " << journeys << '\n';
    cout << "Network total: " << networkTotal << " paise\n";
    cout << "INT_MAX: " << INT_MAX << '\n';

    if (networkTotal > INT_MAX) {
        cout << "Result: int is not sufficient for the total.\n";
    }

    cout << "Result: long long safely stores this total.\n";

    return 0;
}
OUTPUT:
DOUBLE VS INTEGER-PAISE COMPARISON

Journeys: 20000
Double total: Rs 202000.00000007197
Integer-paise total: 20200000 paise
Integer total in rupees: Rs 202000.00
Difference: Rs 7.1973772720e-08

Journeys: 500000
Double total: Rs 5049999.99999573919922113
Integer-paise total: 505000000 paise
Integer total in rupees: Rs 5050000.00
Difference: Rs -4.2608007789e-06

Journeys: 3000000
Double total: Rs 30300000.00155829265713692
Integer-paise total: 3030000000 paise
Integer total in rupees: Rs 30300000.00
Difference: Rs 1.5582926571e-03

INTEGER RANGE ANALYSIS
Maximum fare: 3600 paise
Journeys: 3000000
Network total: 10800000000 paise
INT_MAX: 2147483647
Result: int is not sufficient for the total.
Result: long long safely stores this total.
