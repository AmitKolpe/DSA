#include<iostream>
#include<vector>
using namespace std;

void getperms(vector<int>& nums, int idx, vector<vector<int>>& ans) {
    if (idx == nums.size()) {
        ans.push_back(nums);
        return;
    }
    for (int i = idx; i < nums.size(); i++) {
        swap(nums[idx], nums[i]);
        getperms(nums, idx + 1, ans);  
        swap(nums[idx], nums[i]); 
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    getperms(nums, 0, ans);
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> permutations = permute(nums);

    
    for (const auto& p : permutations) {
        for (int num : p) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
