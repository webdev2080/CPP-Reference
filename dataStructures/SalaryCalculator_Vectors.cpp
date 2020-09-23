#include <iostream>
#include <vector>
using namespace std;

int main() {
   const int MAX_ELEMENTS = 10;
   int annualSalary       = 0;
   double taxRate         = 0.0;
   int taxToPay           = 0;
   int numSalaries        = 0;
   bool keepLooking       = true;
   int i = 0;
   vector<int> salaryBase(5);
   vector<double> taxBase(5);

   salaryBase.at(0) = 0;
   salaryBase.at(1) = 20000;
   salaryBase.at(2) = 50000;
   salaryBase.at(3) = 100000;
   salaryBase.at(4) = 99999999;

   taxBase.at(0) = 0.0;
   taxBase.at(1) = 0.10;
   taxBase.at(2) = 0.20;
   taxBase.at(3) = 0.30;
   taxBase.at(4) = 0.40;

   cout << "\nEnter annual salary (0 to exit): " << endl;
   cin >> annualSalary;

   while (annualSalary > 0) {
      i = 0;
      keepLooking = true;

      // Search for the appropriate table row for given annualSalary
      while ((i < salaryBase.size()) && keepLooking) {
         if (annualSalary <= salaryBase.at(i)) {
            taxRate = taxBase.at(i);
            keepLooking = false;
         }
         else {
            ++i;
         }
      } // End inner loop (search for appropriate table row)

      taxToPay = static_cast<int>(annualSalary * taxRate);   // Truncate tax to an integer amount

      cout << "Annual salary: " << annualSalary <<
              "\tTax rate: " << taxRate <<
              "\tTax to pay: " << taxToPay << endl;

      // Get the next annual salary
      cout << "\nEnter annual salary (0 to exit): " << endl;
      cin >> annualSalary;
   } // End outer while loop (valid annualSalary entered)

  return 0;
}
