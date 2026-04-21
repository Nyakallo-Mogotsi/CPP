/*For this assignment you are required to use pointers. No square brackets are allowed in
the code apart from the initial declaration of the array.

Write a program to process rainfall figures.

Declare an array with the rainfall figures for each of the 12 months of the year.
Use the statements below in your main function to call functions to process the rainfall
figures. Declare the variables (pointers) used in the given statements in the main function

The displayData() function must display the month numbers and rainfall figures.

The calcAve() function must calculate the average rainfall figure for the 12 months as a
double data type.

The findHighestRainfall() function must find the highest rainfall figure in the array.
The average and highest rainfall figures must be displayed with code in the main function.*/

#include <iostream>

using namespace std;

void displayData(int *pCounter, int *pRain  )
{
    printf("%-10s %-15s" , "#Month" , "Rainfall Figures(mm)\n");

    for (int pCounter=0 ; pCounter<12 ; pCounter++)
    {
        printf("%-10d %-15d\n" , pCounter+1 , *(pRain + pCounter));
    }
}

void calcAve(int *pRain ,int *pCounter , double *pAve )
{
    for (int pCounter=0 ; pCounter<12 ; pCounter++)
    {
         double total = total + *(pRain + pCounter);
         *pAve = total/12.0;
    }
    cout << "Average rainfall is " << *pAve << endl;
}

void findHighestRainfall(int *pRain , int *pHighest , int *pCounter)
{

    *pHighest = *pRain;

    for(int pCounter = 1; pCounter < 12; pCounter++)
    {
        if(*(pRain + pCounter) > *pHighest)
        {
            *pHighest = *(pRain + pCounter);
        }
    }
    cout << "Highest rainfall is " << *pHighest << endl;

}


int main()
{
    const int SIZE = 12;
    int arrRain[SIZE]={234,325,287,112,16,0,0,0,45,123,224,204};

    int* pRain = arrRain;

    int counter = 0;
    int *pCounter = &counter;

    double ave;
    double *pAve = &ave;

    int highest;
    int *pHighest = &highest;
    displayData(pCounter,pRain);

    calcAve(pRain,pCounter,pAve);

    findHighestRainfall(pRain , pHighest , pCounter);

    return 0;
}
