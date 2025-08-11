#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;

    void twosum(vector<int>& nums, int target, int i, int j) {
        while (i < j) {
            if (nums[i] + nums[j] > target) {
                j--;
            }
            else if (nums[i] + nums[j] < target) {
                i++;
            }
            else {
                // Found a pair
                result.push_back({-target, nums[i], nums[j]});

                // Skip duplicates
                while (i < j && nums[i] == nums[i + 1]) i++;
                while (i < j && nums[j] == nums[j - 1]) j--;

                i++;
                j--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return {};
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicate i

            int target = -nums[i];
            twosum(nums, target, i + 1, n - 1);
        }

        return result;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    vector<vector<int>> ans = sol.threeSum(nums);

    cout << "Triplets with sum 0 are:\n";
    for (auto &triplet : ans) {
        for (int x : triplet) cout << x << " ";
        cout << "\n";
    }
}
