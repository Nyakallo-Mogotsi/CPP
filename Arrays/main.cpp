/*Design a C++ program using arrays to calculate and display the income of employees
based on hours worked.
The program must do the following:
• Declare an array arrNames of type string with the names of 10 employees.
• Using a loop structure, display the name of each employee and ask the user to
enter the number of hours worked.
The numbers of hours entered must be in the range of 1 to 40 and of type integer.
Use a loop structure to display a message to try again if the value entered is outside
the correct range.
  
NOTE:
• Only valid hours must be saved in the arrHours array.
• The arrHours array must have the same number of spaces as the arrNames
array since these two arrays are parallel arrays.
Parallel arrays means that each element in the one array (arrNames) is related to the
same element in the other array (arrHours).

For example:
If the name Sam has been saved in arrNames and the first employee and the value of 12
has been saved as the first element in the arrHours array, it means that the number of
hours that Sam has worked is 12.

Write a function called calculateSalary() that will receive the two arrays as
parameters.
Ask the user to enter the hourly wage

Call the calculateSalary() function from the main function.
*/

#include <iostream>
#include <iomanip>

using namespace std;


void calculateSalary(string arrNames[10],int arrHours[10])
{
    double wage, salary;
    cout << "\nEnter hourly wage: ";
    cin >> wage;
    cout << "\nEmployees and their salaries" << endl;
    cout << "Name        Hours       Salary" << endl;
    for (int k = 0; k < 10; k++)
    {
       salary = arrHours[k] * wage;
       cout << left << setw(10) << arrNames[k] << right << setw(5)<< arrHours[k] << setw(15) << fixed << setprecision(2) << salary << endl;
    }
}

int main()
{

    const int NUM_WORKERS = 10;
    string arrNames[] = {"Lerato","Julia", "Thato", "AJ", "Kamva", "Inathi", "Anathi", "Molemo", "Phila", "Midana" };
    int arrHours [NUM_WORKERS];
    int hours =0;

    for (int k = 0; k < NUM_WORKERS; k++)
    {
        do
        {
          cout << "Enter the number of hours for " << arrNames[k] << ": ";
          cin >> hours;
          if (!(hours >= 1 && hours <=40))
            cout << "Incorrect value for hours worked, please try again" << endl;
        }
        while (!(hours >= 1 && hours <=40));
        arrHours[k] = hours;
    }

    calculateSalary(arrNames, arrHours);

    cout << "\nDone!" << endl;
    return 0;
}

