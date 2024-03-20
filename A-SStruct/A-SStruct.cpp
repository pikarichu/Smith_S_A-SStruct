// A-SStruct.cpp : This file contains the 'main' function. Program execution begins and ends there.
//This program takes the data of miles run per day by runners from a text file, calculates the total miles run and average miles run per day
//and outputs that to a table in a terminal window.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int NROWS = 5;
const int NCOLS = 7;
const string fileName = "runners.txt";

struct runner {
    string name;
    int miles[NCOLS];
    int total;
    float average;
};

//Reads the data in from the file to the struct
//Preconditions: File "runners.txt", the runners struct and the runnersList array of structs
//Postconditions: Each runner struct is populated with the runner's name and an array of miles run per day,
//then added to the runnersList array of structs
int readData(runner runnersList[]);

//Calculates the total amount of miles run and the average miles run per day
//Preconditons: The populated array of structs, runnersList
//Postconditions: Average and total added to each struct in runnersList
void calcAverageTotal(runner runnersList[]);

//Inputs the data into a table for viewing
//Preconditions: Fully populated runnersList array of runners structs
//Postconditions: Outputs a table into the terminal with all of the data from the arrays
void displayResults(runner runnersList[]);

int main()
{
    runner runnersList[NROWS];
    readData(runnersList);
    calcAverageTotal(runnersList);
    displayResults(runnersList);
}

int readData(runner runnersList[])
{
    ifstream inFile;
    inFile.open(fileName);
    if (!inFile.is_open())
    {
        cout << "Could not open file\n";
        return -1;
    }
    for (int i = 0; i < NROWS; i++)
    {
        inFile >> runnersList[i].name;
        for (int j = 0; j < NCOLS; j++)
        {
            inFile >> runnersList[i].miles[j];
        }
    }
    return 0;
}

void calcAverageTotal(runner runnersList[])
{
    int total = 0;
    for (int i = 0; i < NROWS; i++)
    {
        for (int j = 0; j < NCOLS; j++)
        {
            total += runnersList[i].miles[j];

        }
        runnersList[i].total = total;
        runnersList[i].average = float(total) / float(NCOLS);
    }
}

void displayResults(runner runnersList[])
{
    for (int i = 0; i < NROWS; i++)
    {
        cout << setw(8) << runnersList[i].name << " ";
        for (int j = 0; j < NCOLS; j++)
        {
            cout << setw(2) << runnersList[i].miles[j] << " ";
        }
        cout << "Total: " << runnersList[i].total << " " << "Average: " << runnersList[i].average << endl;
    }
}