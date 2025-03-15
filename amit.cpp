#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class permutation {
public:
    void merge(vector<int>& A) {
        int pivot = -1, n = A.size();

        // Step 1: Find the pivot (first element from the end that is smaller than its next)
        for (int i = n - 2; i >= 0; i--) {
            if (A[i] < A[i + 1]) {
                pivot = i;
                break;
            }
        }

        // Step 2: If no pivot found, reverse the array (last permutation case)
        if (pivot == -1) {
            reverse(A.begin(), A.end());
            return;
        }

        // Step 3: Find the rightmost element greater than A[pivot] and swap
        for (int i = n - 1; i > pivot; i--) {
            if (A[i] > A[pivot]) {
                swap(A[i], A[pivot]);
                break;
            }
        }

        // Step 4: Reverse the elements to the right of pivot
        reverse(A.begin() + pivot + 1, A.end());
    }
};

int main() {
    vector<int> A = {1, 2, 3}; // Example input

    permutation p;
    p.merge(A); // Corrected function call

    cout << "The next permutation is: ";
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
