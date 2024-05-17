//Write a program to sort the elements of an array using Heap sort. The program should report the number of comparisons.

#include <iostream>
using namespace std;

int partition(int arr[], int low, int high, int& comparisons) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        comparisons++; // increment comparisons
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int& comparisons) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons);

        quickSort(arr, low, pi - 1, comparisons);
        quickSort(arr, pi + 1, high, comparisons);
    }
}

int main() {
    int arr[] = {55, 34, 12, 32, 89, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int comparisons = 0;

    quickSort(arr, 0, n - 1, comparisons);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\nComparisons made: " << comparisons << endl;

    return 0;
}