#ifndef SORTING_H
#define SORTING_H

void sortMenu(int arr[], int size);


void selectionSort(int arr[], int size);

int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
#endif 

