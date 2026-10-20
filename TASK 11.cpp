#include <iostream> 
#include <iomanip> 
#include <string>
using namespace std;
constexpr long long FARE_PAISE = 1000;
// Rs 10.00
constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000; 
// Rs 50.00
long long calculateFarePaise(bool peak) {
long long fare = FARE_PAISE;

if (peak) {
    fare += fare * PEAK_SURCHARGE_PERCENT / 100;
}

return fare;
}

double calculateFareRupees(bool peak) {
double fare = 10.0;

if (peak) {
    fare += fare * 20.0 / 100.0;
}

return fare;
}

void compareTotals(long long journeys, bool peak) {
long long farePaise = calculateFarePaise(peak);
double fareRupees = calculateFareRupees(peak);

long long totalPaise = journeys * farePaise;
double totalRupees = journeys * fareRupees;

cout << "\nJourneys: " << journeys << '\n';
cout << "Integer-paise total: Rs "
     << totalPaise / 100 << '.'
     << setw(2) << setfill('0') << totalPaise % 100
     << setfill(' ') << '\n';

cout << fixed << setprecision(2);
cout << "Double total:        Rs " << totalRupees << '\n';

double difference = totalRupees - totalPaise / 100.0;
cout << "Difference:          Rs "
     << setprecision(8) << difference << '\n';
cout << setprecision(2);
}

int main() {
cout << "METRO FARE DESIGN EVALUATION\n";
cout << "Base fare: Rs 10.00\n";
cout << "Peak surcharge: 20%\n";
cout << "Minimum remaining balance: Rs 50.00\n";

cout << "\n--- Off-peak comparison ---\n";
compareTotals(20000, false);
compareTotals(500000, false);
compareTotals(3000000, false);

cout << "\n--- Peak comparison ---\n";
compareTotals(20000, true);
compareTotals(500000, true);
compareTotals(3000000, true);

cout << "\nRecommended design:\n";
cout << "1. Store money as integer paise using long long.\n";
cout << "2. Define fares and limits with constexpr constants.\n";
cout << "3. Use enum class Zone for type-safe zones.\n";
cout << "4. Use SmartCard with a private balance.\n";
cout << "5. Keep fare calculation in a separate function or class.\n";
cout << "6. Validate inputs and test boundary cases.\n";

return 0;
}

OUTPUT:
METRO FARE DESIGN EVALUATION
Base fare: Rs 10.00
Peak surcharge: 20%
Minimum remaining balance: Rs 50.00

--- Off-peak comparison ---

Journeys: 20000
Integer-paise total: Rs 200000.00
Double total:        Rs 200000.00
Difference:          Rs 0.00000000

Journeys: 500000
Integer-paise total: Rs 5000000.00
Double total:        Rs 5000000.00
Difference:          Rs 0.00000000

Journeys: 3000000
Integer-paise total: Rs 30000000.00
Double total:        Rs 30000000.00
Difference:          Rs 0.00000000

--- Peak comparison ---

Journeys: 20000
Integer-paise total: Rs 240000.00
Double total:        Rs 240000.00
Difference:          Rs 0.00000000

Journeys: 500000
Integer-paise total: Rs 6000000.00
Double total:        Rs 6000000.00
Difference:          Rs 0.00000000

Journeys: 3000000
Integer-paise total: Rs 36000000.00
Double total:        Rs 36000000.00
Difference:          Rs 0.00000000

Recommended design:
1. Store money as integer paise using long long.
2. Define fares and limits with constexpr constants.
3. Use enum class Zone for type-safe zones.
4. Use SmartCard with a private balance.
5. Keep fare calculation in a separate function or class.
6. Validate inputs and test boundary cases.
