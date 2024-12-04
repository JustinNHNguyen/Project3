#include <vector>
#include "game.h"

using namespace std;

// Merge Sort Implementation
void merge(vector<game>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<game> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].getprice() <= R[j].getprice()) {
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

void mergeSort(vector<game>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Quick Sort Implementation
int partition(vector<game>& arr, int low, int high) {
    float pivot = arr[high].getprice();
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].getprice() < pivot) {
            i++;
            arr[i].swap(arr[j]);
        }
    }

    arr[i + 1].swap(arr[high]);
    return i + 1;
}

void quickSort(vector<game>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

