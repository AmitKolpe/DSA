#include <iostream>
#include <vector>
#include <climits> // For INT_MIN

using namespace std;

int main() {
    vector<int> nums = {1, -3, 2, 1, -1}; // Example input array
    int currSum = 0, maxSum = INT_MIN;

    for (int val : nums) {
        currSum += val;
        maxSum = max(currSum, maxSum);
        if (currSum < 0) {
            currSum = 0;
        }
    }

    cout << "Maximum Subarray Sum: " << maxSum << endl;

    return 0; // Indicates successful execution
}
