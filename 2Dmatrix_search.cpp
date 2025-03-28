#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& mat, int target) {
    int m = mat.size(), n = mat[0].size();
    int r = 0, c = n - 1; // Start from top-right corner

    while (r < m && c >= 0) { // Corrected condition (r < m instead of r < n)
        if (target == mat[r][c]) {
            return true;
        } else if (target < mat[r][c]) {
            c--; // Move left
        } else {
            r++; // Move down
        }
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };
    
    int target = 5;

    if (searchMatrix(matrix, target)) {
        cout << "Target " << target << " found in the matrix." << endl;
    } else {
        cout << "Target " << target << " not found in the matrix." << endl;
    }

    return 0;
}
