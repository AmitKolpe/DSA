#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& A, int mid, int low, int high) {
    int i = low, j = mid + 1, k = 0;
    vector<int> B(high - low + 1); // Temporary array

    // Merging two sorted array
    while (i <= mid && j <= high) {
        if (A[i] < A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }

    // Copy remaining elements from left half
    while (i <= mid) {
        B[k++] = A[i++];
    }

    // Copy remaining elements from right half
    while (j <= high) {
        B[k++] = A[j++];
    }

    // Copy back sorted elements to original array
    for (int m = 0; m < B.size(); m++) {
        A[low + m] = B[m];
    }
}

void mergeSort(vector<int>& A, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, mid, low, high);
    }
}

int main() {
    vector<int> A = {5, 6, 0, 1, 2};
    
    cout << "Original array: ";
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    mergeSort(A, 0, A.size() - 1);

    cout << "Sorted array: ";
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
