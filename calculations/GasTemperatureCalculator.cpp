#include <iostream>
#include <iomanip>
using namespace std;

const double GAS_CONSTANT = 8.3144621;  //  J / (mol * K)

/* Converts a pressure, volume, and number of moles
 of a gas into a temperature. */
double PVnToTemp(double gasPressure, double gasVolume, double numMoles) {
   return (gasPressure * gasVolume) / (numMoles * GAS_CONSTANT);
}

int main() {
   double gasPress = 0.0;  // User defined pressure
   double gasVol   = 0.0;  // User defined volume
   double gasMoles = 0.0;  // User defined moles
   
   // Prompt user for input parameters
   cout << "Enter gas pressure (in Pascals): ";
   cin >> gasPress;
   
   cout << "Enter gas volume (in cubic meters): ";
   cin >> gasVol;
   
   cout << "Enter number of moles: ";
   cin >> gasMoles;
   
   // Call function to calculate temperature
   cout << "Temperature = ";
   cout << fixed << setprecision(2)
        << PVnToTemp(gasPress, gasVol, gasMoles) << " K"
        << endl;
   
   return 0;
}
