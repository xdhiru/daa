//Write a program to sort the elements of an array using Merge sort. The program should report the number of comparisons.

#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i, int& comparisons) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
        comparisons++; // increment comparisons
    }

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
        comparisons++; // increment comparisons
    }

    if (largest!= i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest, comparisons);
    }
}

void heapSort(int arr[], int n, int& comparisons) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, comparisons);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, comparisons);
    }
}

int main() {
    int arr[] = {33, 6, 1, 90, 4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int comparisons = 0;

    heapSort(arr, n, comparisons);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\nComparisons made: " << comparisons << endl;

    return 0;
}