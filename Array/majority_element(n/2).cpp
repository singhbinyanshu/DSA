#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int maj = -1; // Initial placeholder
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (count == 0) {
                maj = nums[i];
                count = 1;
            } else if (nums[i] == maj) {
                count++;
            } else {
                count--;
            }
        }
        return maj;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    int result = obj.majorityElement(nums);
    cout << "Majority element (> n/2 times): " << result << endl;

    return 0;
}
