#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>> result;

        // Step 1: Store value with original index
        for (int i = 0; i < n; i++) {
            result.push_back({nums[i], i});
        }

        // Step 2: Sort by value
        sort(result.begin(), result.end());

        // Step 3: Two-pointer search
        int left = 0, right = n - 1;
        while (left < right) {
            int sum = result[left].first + result[right].first;

            if (sum == target) {
                return {result[left].second, result[right].second};
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }

        return {};
    }
};

int main() {
    vector<int> nums = {3, 2, 4};
    int target = 6;
    Solution sol;
    vector<int> ans = sol.twoSum(nums, target);
    if (!ans.empty()) {
        cout << "Indices: " << ans[0] << ", " << ans[1] << "\n";
    } else {
        cout << "No pair found\n";
    }
}
