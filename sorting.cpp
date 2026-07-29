#include <iostream>
#include "sorting.h"

using namespace std;

void selectionSort(int arr[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        int minIndex = i;

        for(int j = i + 1; j < size; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    cout << "\nSelection sort completed Successfully\n";

}

void sortMenu(int arr[], int size)
{
    int choice;

    cout << "\n----- Sorting Menu -----\n";
    cout << "1. Selection Sort\n";
    cout << "2. Quick Sort\n";
    cout << "3. Merge Sort\n";
    cout << "4. Back to Main Menu\n";
    cout << "\nEnter your choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            selectionSort(arr, size);
            cout << "\nRecords sorted using Selection Sort.\n";
            displaySortedArray(arr, size);   // <-- Write it here
            break;

        case 2:
            quickSort(arr, 0, size - 1);
            cout << "\nRecords sorted using Quick Sort.\n";
            displaySortedArray(arr, size);   // <-- Write it here
            break;

        case 3:
            mergeSort(arr, 0, size - 1);
            cout << "\nRecords sorted using Merge Sort.\n";
            displaySortedArray(arr, size);   // <-- Write it here
            break;

        case 4:
            cout << "\nReturning to Main Menu...\n";
            break;

        default:
            cout << "\nInvalid choice! Please try again.\n";
    }
}
    int partition(int arr[], int low, int high)
    {
        int pivot = arr[high];
        int i = low - 1;

        for(int j = low; j < high; j++)
        {
            if(arr[j] <= pivot)
            {
                i++;
                
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        return i + 1;
    }

    void quickSort(int arr[], int low, int high)
    {
        if(low < high)
        {
            int pivotIndex = partition(arr, low, high);

            quickSort(arr, low, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, high);
        }
    }

    void merge(int arr[], int left, int mid, int right)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int L[n1], R[n2];

         for(int i = 0; i < n1; i++)
            L[i] = arr[left + i];

        for(int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];
        

        int i = 0;
        int j = 0;
        int k = left;

        while(i < n1 && j < n2)
        {
            if(L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while(i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }

        while(j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }

    }

    void mergeSort(int arr[], int left, int right)
    {
        if(left < right)
        {
            int mid = left + (right - left) / 2;

            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);

            merge(arr, left, mid, right);
        }
    }

   void displaySortedArray(int arr[], int size)
{
    cout << "\n----- Sorted Records -----\n\n";

    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";

        if((i + 1) % 10 == 0)
            cout << endl;
    }

    cout << endl;
}