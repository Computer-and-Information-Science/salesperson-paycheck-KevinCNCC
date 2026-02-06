#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
int main() {
  std::cout << "Hello World!\n";

  ifstream inData;
  ofstream outData;

  string fileName, finishedFile;

  cout << "What is the file you would like to Calculate?" << endl;
  cin >> fileName;

  inData.open(fileName);
 
  outData.open("output.dat");

  string firstName, lastName;
  double baseSalary, totalCommissions, commissionPercent, expenses, beforeCommission, total;
  outData << fixed << setprecision(2);

  inData >> firstName >> lastName >> baseSalary >> commissionPercent >> beforeCommission >> expenses;
  totalCommissions = (beforeCommission*commissionPercent)/100;
  total = baseSalary + totalCommissions + expenses;

  outData << "Payroll data for " << firstName << " " << lastName << endl;
  outData << "   " << endl;
  outData << "Base Salary: " << setw(12) << baseSalary << endl;
  outData << "Commission: " << setw(13) << totalCommissions << " (" << commissionPercent << "%" << " of " << beforeCommission << ")" << endl;
  outData << "Expenses: " << setw(15) << expenses << endl;
  outData << setw(25) << "--------" << endl;
  outData << "Total: " << setw(18) << total << endl;


  printf("Payroll data for %s %s\n", firstName.c_str(), lastName.c_str());
  printf("\n");
  printf("Base Salary: %12.2f\n", baseSalary);
  printf("Commission: %13.2f (%d%% of %.2f)\n", totalCommissions, (int)commissionPercent, beforeCommission);
  printf("Expenses: %15.2f\n", expenses);
  printf("%25s\n", "--------");
  printf("Total: %18.2f\n", total);
  inData.close();
  outData.close();
  return 0;
}