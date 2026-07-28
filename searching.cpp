#include <iostream>
#include "searching.h"

using namespace std;

int binarySearch(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1; 
}

void searchMenu(int arr[], int size)
{
    int choice;
    int target;
    int index;

    cout << "\n----- Searching Menu -----\n";
    cout << "1. Binary Search\n";
    cout << "2. Interpolation Search\n";
    cout << "3. Back to Main Menu\n";
    cout << "\nEnter your choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
        {
            cout << "\nEnter the number to search: ";
            cin >> target;

            index = binarySearch(arr, size, target);

            if(index != -1)
                cout << "\nNumber found at index: " << index << endl;
            else
                cout << "\nNumber not found in the array.\n";

            break;
        }

        case 2:
        {
            cout << "\nEnter the number to search: ";
            cin >> target;

            index = interpolationSearch(arr, size, target);

            if(index != -1)
                cout << "\nNumber found at index: " << index << endl;
            else
                cout << "\nNumber not found in the array.\n";

            break;
        }

        case 3:
            return;

        default:
            cout << "\nInvalid choice! Please try again.\n";
    }
}

int interpolationSearch(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;

    while(low <= high &&
          target >= arr[low] &&
          target <= arr[high])
    {
        if(arr[low] == arr[high])
        {
            if(arr[low] == target)
                return low;
            else
                return -1;
        }

        int pos = low + ((target - arr[low]) * (high - low))
                        / (arr[high] - arr[low]);

        if(arr[pos] == target)
            return pos;

        if(arr[pos] < target)
            low = pos + 1;
        else
            high = pos - 1;
    }

    return -1;
}

