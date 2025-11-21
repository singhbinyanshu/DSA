#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0;
        int maj1 = NULL;

        int count2 = 0;
        int maj2 = NULL;

        // First pass - find potential candidates
        for (int i = 0; i < n; i++) {
            if (nums[i] == maj1) {
                count1++;
            } else if (nums[i] == maj2) {
                count2++;
            } else if (count1 == 0) {
                maj1 = nums[i];
                count1 = 1;
            } else if (count2 == 0) {
                maj2 = nums[i];
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        // Second pass - count frequencies
        vector<int> result;
        int freq1 = 0;
        int freq2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == maj1) {
                freq1++;
            } else if (nums[i] == maj2) {
                freq2++;
            }
        }

        if (freq1 > floor(n / 3)) {
            result.push_back(maj1);
        }
        if (freq2 > floor(n / 3)) {
            result.push_back(maj2);
        }
        return result;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    vector<int> ans = obj.majorityElement(nums);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
