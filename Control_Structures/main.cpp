/*Design a C++ program to do the administration of participants in a fun run competition.
Participants can run a distance of 5 kilometers, 10 kilometers or 15 kilometers.
Registration fees are as follows:
Distance Fee
5 Kilometers R 65.00
10 Kilometers R 100.00
15 Kilometers R 150.00
The program must do the following:
Ask whether a participant must be registered (Y or N). If Y, display the distances as
options to choose from (use a switch statement) and allow the user to choose one of the
distances from the list.
Keep on registering participants until there are no more participants to register.
The program must keep track of the number of participants registered per distance
category, the amount received per distance category and total amount received.
The program must also to identify the category with the highest income in terms of
registration fees.
Display the following:
Category Num athletes Income
5 kilometers: xx R xxxx.xx
10 kilometers: xx R xxxx.xx
15 kilometers: xx R xxxx.xx
Total number of participants: xx
Total income: R xxxx.xx
Category with highest income: xxxxxxx
Specifications:
• You need THREE constant variables: KM5_FEE, KM10_FEE and KM15_FEE
• Counter variables MUST be initialized to the value of 0 when declared.
• Small or capital letters must be accepted by the program as input.
• Output must be neatly formatted in columns as shown in the example output*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

int main() {
    
    const double KM5_FEE = 65.00;
    const double KM10_FEE = 100.00;
    const double KM15_FEE = 150.00;

    
    int count5 = 0, count10 = 0, count15 = 0;
    double income5 = 0.0, income10 = 0.0, income15 = 0.0;

    char registerChoice;
    do {
        cout << "Register a participant? (Y/N): ";
        cin >> registerChoice;
        registerChoice = toupper(registerChoice);

        if (registerChoice == 'Y') {
            int distanceChoice;
            cout << "\nChoose distance category:\n";
            cout << "1. 5 Kilometers\n";
            cout << "2. 10 Kilometers\n";
            cout << "3. 15 Kilometers\n";
            cout << "Enter choice (1-3): ";
            cin >> distanceChoice;

            switch (distanceChoice) {
                case 1:
                    count5++;
                    income5 += KM5_FEE;
                    break;
                case 2:
                    count10++;
                    income10 += KM10_FEE;
                    break;
                case 3:
                    count15++;
                    income15 += KM15_FEE;
                    break;
                default:
                    cout << "Invalid choice. Participant not registered.\n";
            }
        }
    } while (registerChoice == 'Y');

    
    int totalParticipants = count5 + count10 + count15;
    double totalIncome = income5 + income10 + income15;

    
    string highestCategory;
    double maxIncome = income5;
    highestCategory = "5 kilometers";
    if (income10 > maxIncome) {
        maxIncome = income10;
        highestCategory = "10 kilometers";
    }
    if (income15 > maxIncome) {
        maxIncome = income15;
        highestCategory = "15 kilometers";
    }

  
    cout << "\nCategory          Num athletes   Income\n";
    cout << left << setw(15) << "5 kilometers:" << setw(13) << count5 
         << "R " << fixed << setprecision(2) << income5 << endl;
    cout << left << setw(15) << "10 kilometers:" << setw(13) << count10 
         << "R " << fixed << setprecision(2) << income10 << endl;
    cout << left << setw(15) << "15 kilometers:" << setw(13) << count15 
         << "R " << fixed << setprecision(2) << income15 << endl;

    cout << "\nTotal number of participants: " << totalParticipants << endl;
    cout << "Total income: R " << fixed << setprecision(2) << totalIncome << endl;
    cout << "Category with highest income: " << highestCategory << endl;

    return 0;
}
