#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting.h"
#include "searching.h"

using namespace std;

const int SIZE = 100;
int arr[SIZE];

void generateData();
void displayRecords();
void menu();

int main()
{
    generateData();
    menu();

    return 0;
}
void generateData()
{
   srand(time(0));

    for(int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 1000 + 1;
    }
}

void displayRecords()
{
    cout << "\n----- All Records -----\n\n";

    for(int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << "\t";

        if((i + 1) % 10 == 0)
        {
            cout << endl;
        }
    }

    cout << endl;
}
void menu()
{
    int choice;

    do
    {
        cout << "\n========== NEW MENU ==========\n";
        cout << "1. Display All Records\n";
        cout << "2. Sort Records\n";
        cout << "3. Search for Number\n";
        cout << "4. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
    
        {
            case 1:
                displayRecords();
                break;
            case 2:
                sortMenu(arr, SIZE); 
                break;
            case 3:
                searchMenu(arr, SIZE);
                break;
            case 4:
                cout << "\nExiting.\n";
                break;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    } while(choice != 4);
}
