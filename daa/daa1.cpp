#include <iostream>
using namespace std;

void insertionSort(int arr[], int n, int& comparisons) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        comparisons = 0; // reset comparisons for each iteration
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            comparisons++; // increment comparisons
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {10, 20, 7, 15, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int comparisons = 0;

    insertionSort(arr, n, comparisons);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\nComparisons made: " << comparisons << endl;

    return 0;
}
