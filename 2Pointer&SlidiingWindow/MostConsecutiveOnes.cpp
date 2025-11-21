#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxlen = 0, zeroes = 0;
        int l = 0, r = 0;

        while (r < n) {
            if (nums[r] == 0) {
                zeroes++;
            }

            // shrink window if zeroes > k
            while (zeroes > k) {
                if (nums[l] == 0) {
                    zeroes--;
                }
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
            r++;
        }

        return maxlen;
    }
};

int main() {
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements (0s and 1s): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter k: ";
    cin >> k;

    Solution sol;
    int ans = sol.longestOnes(nums, k);

    cout << "Longest subarray length = " << ans << endl;

    return 0;
}
