/*
Write a program for a FunRun event. The information required for each participant in the FunRun
are the name, date of birth (day, a month and a year (integer values)), gender (F or M) and time it
took to complete the funrun in minutes.

Define a struct Participant with members required for a participant. Define a Date struct which
contains the members day, month and year of type integer, and use the Date struct as a nested
struct in the Participant struct.
  
Write a getInfo() function that requests the user to enter the information of one participant, save
the information in a struct variable and return the struct variable to the call statement.
  
In the main function, declare an array to keep the information of up to 100 participants.
Use a while loop and the getInfo() to enter and save the information of a number of participants in
the participants array.
  
Write a function called calculateAge() that receives the year of birth of the participant and calculate
and return the age of the participant. Declare and use a constant variable THIS_YEAR with the value
of 2022.
  
Write a displayData() function that receives the array and the counter variable for the array. Display
a numbered list with the name, gender, birth year, age and time of the participants.

Write a function called findWinner() that receives the array of Participants and the counter variable
to find the winner. Return the index value of the winner in the array.
  
Write a function called displayWinner() that will receive the array and the index value of the winner
and display the information of the winner

In the main function, call the relevant functions enter the correct order to enter the data and display
the numbered list with the name, gender, year of birth, age and time of participants.
Call the relevant functions to determine and display the name, date of birth, age and time of the
winner.*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Constant for current year
const int THIS_YEAR = 2022;

// Date struct
struct Date {
    int day;
    int month;
    int year;
};

// Participant struct with nested Date
struct Participant {
    string name;
    Date dob;
    char gender;
    int time; // minutes to complete fun run
};

// Function to get info for one participant
Participant getInfo() {
    Participant p;
    cout << "\nEnter participant name: ";
    cin.ignore(); // clear buffer
    getline(cin, p.name);

    cout << "Enter date of birth (day month year): ";
    cin >> p.dob.day >> p.dob.month >> p.dob.year;

    cout << "Enter gender (M/F): ";
    cin >> p.gender;
    p.gender = toupper(p.gender);

    cout << "Enter time to complete fun run (minutes): ";
    cin >> p.time;

    return p;
}

// Function to calculate age
int calculateAge(int birthYear) {
    return THIS_YEAR - birthYear;
}

// Function to display all participants
void displayData(Participant arr[], int count) {
    cout << "\nList of Participants:\n";
    cout << left << setw(5) << "No." << setw(20) << "Name"
         << setw(8) << "Gender" << setw(12) << "BirthYear"
         << setw(6) << "Age" << setw(8) << "Time" << endl;
    cout << "-------------------------------------------------------------\n";
    for (int i = 0; i < count; i++) {
        cout << left << setw(5) << (i + 1)
             << setw(20) << arr[i].name
             << setw(8) << arr[i].gender
             << setw(12) << arr[i].dob.year
             << setw(6) << calculateAge(arr[i].dob.year)
             << setw(8) << arr[i].time << endl;
    }
}

// Function to find winner (lowest time)
int findWinner(Participant arr[], int count) {
    int winnerIndex = 0;
    int bestTime = arr[0].time;
    for (int i = 1; i < count; i++) {
        if (arr[i].time < bestTime) {
            bestTime = arr[i].time;
            winnerIndex = i;
        }
    }
    return winnerIndex;
}

// Function to display winner
void displayWinner(Participant arr[], int index) {
    cout << "\nWinner Information:\n";
    cout << "Name: " << arr[index].name << endl;
    cout << "Date of Birth: " << arr[index].dob.day << "/"
         << arr[index].dob.month << "/" << arr[index].dob.year << endl;
    cout << "Gender: " << arr[index].gender << endl;
    cout << "Age: " << calculateAge(arr[index].dob.year) << endl;
    cout << "Time: " << arr[index].time << " minutes" << endl;
}

int main() {
    Participant participants[100];
    int count = 0;
    char choice;


    do {
        if (count >= 100) {
            cout << "Maximum participants reached.\n";
            break;
        }
        participants[count] = getInfo();
        count++;

        cout << "Add another participant? (Y/N): ";
        cin >> choice;
        choice = toupper(choice);
    } while (choice == 'Y');

    // Display all participants
    displayData(participants, count);

    // Find and display winner
    int winnerIndex = findWinner(participants, count);
    displayWinner(participants, winnerIndex);

    return 0;
}


