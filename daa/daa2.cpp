//Write a program to sort the elements of an array using Insertion sort. The program should report the number of comparisons.

#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r, int& comparisons) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        comparisons++; // increment comparisons
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r, int& comparisons) {
    if (l >= r) {
        return;
    }

    int m = l + (r - l) / 2;

    mergeSort(arr, l, m, comparisons);
    mergeSort(arr, m + 1, r, comparisons);

    merge(arr, l, m, r, comparisons);
}

int main() {
    int arr[] = {11, 30, 70, 15, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    int comparisons = 0;

    mergeSort(arr, 0, n - 1, comparisons);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\nComparisons made: " << comparisons << endl;

    return 0;
}