/*Create a C++ project to rate Restaurants. Use your surname and your student number as
part of the name of the project.

Create a struct called Restaurant that consists of the name of the restaurant, rating
for food (out of 10) and rating for service (out of 10).

Declare an array to store up to 12 Restaurant structs.
Enter the information of a few restaurants from the keyboard and store the structs in
the array. Use a variable to keep track of the actual number of structs stored in the
array

Write displayData() function to receive the array and number of restaurants and
display a numbered list of all the restaurants and their ratings.
In the main function:
Call the displayData() function.

The user must be able to change the ratings of a restaurant.
Ask the user to enter the number of a restaurant on the list.
If the number is not within the range of the numbers on the list, show a suitable
message and allow the user to enter another number until a valid number is
entered.

Display the name of the selected restaurant and the current rating for food and
service.
Ask the user to enter the new rating for food.
Ask the user to enter the new rating for service.
Write code to change the ratings to the new ratings that were entered.
Call the displayData function to display the updated list

Write a displayBestRestaurant() function to receive the array and number of
elements and determine which restaurant in the array has the best average rating.
Display the name of the restaurant, the rating for food and the rating for service and
the average rating
Call the function from the main function.*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Struct
struct Restaurant {
    string name;
    int foodRating;    // out of 10
    int serviceRating; // out of 10
};

// Function to display all restaurants
void displayData(Restaurant arr[], int numRestaurants) {
    cout << "\nList of Restaurants:\n";
    cout << left << setw(5) << "No." << setw(20) << "Name"
         << setw(10) << "Food" << setw(10) << "Service" << endl;
    cout << "---------------------------------------------------\n";
    for (int i = 0; i < numRestaurants; i++) {
        cout << left << setw(5) << (i + 1)
             << setw(20) << arr[i].name
             << setw(10) << arr[i].foodRating
             << setw(10) << arr[i].serviceRating << endl;
    }
}

// Function to display best restaurant based on average rating
void displayBestRestaurant(Restaurant arr[], int numRestaurants) {
    double bestAvg = -1;
    int bestIndex = -1;

    for (int i = 0; i < numRestaurants; i++) {
        double avg = (arr[i].foodRating + arr[i].serviceRating) / 2.0;
        if (avg > bestAvg) {
            bestAvg = avg;
            bestIndex = i;
        }
    }

    if (bestIndex != -1) {
        cout << "\nBest Restaurant:\n";
        cout << "Name: " << arr[bestIndex].name << endl;
        cout << "Food Rating: " << arr[bestIndex].foodRating << endl;
        cout << "Service Rating: " << arr[bestIndex].serviceRating << endl;
        cout << "Average Rating: " << fixed << setprecision(2) << bestAvg << endl;
    }
}

int main() {
    Restaurant restaurants[12];
    int numRestaurants = 0;

    
    char choice;
    do {
        if (numRestaurants >= 12) {
            cout << "Maximum number of restaurants reached.\n";
            break;
        }

        cout << "Enter restaurant name: ";
        cin.ignore(); 
        getline(cin, restaurants[numRestaurants].name);

        cout << "Enter food rating (0-10): ";
        cin >> restaurants[numRestaurants].foodRating;

        cout << "Enter service rating (0-10): ";
        cin >> restaurants[numRestaurants].serviceRating;

        numRestaurants++;

        cout << "Add another restaurant? (Y/N): ";
        cin >> choice;
        choice = toupper(choice);
    } while (choice == 'Y');

  
    displayData(restaurants, numRestaurants);


    int restaurantNumber;
    do {
        cout << "\nEnter the number of a restaurant to update ratings: ";
        cin >> restaurantNumber;
        if (restaurantNumber < 1 || restaurantNumber > numRestaurants) {
            cout << "Invalid number. Try again.\n";
        }
    } while (restaurantNumber < 1 || restaurantNumber > numRestaurants);

    int index = restaurantNumber - 1;
    cout << "\nSelected: " << restaurants[index].name << endl;
    cout << "Current Food Rating: " << restaurants[index].foodRating << endl;
    cout << "Current Service Rating: " << restaurants[index].serviceRating << endl;

    cout << "Enter new food rating (0-10): ";
    cin >> restaurants[index].foodRating;
    cout << "Enter new service rating (0-10): ";
    cin >> restaurants[index].serviceRating;


    displayData(restaurants, numRestaurants);

    displayBestRestaurant(restaurants, numRestaurants);

    return 0;
}

