#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: Detect cycle (meeting point)
        do {
            slow = nums[slow];           // move 1 step
            fast = nums[nums[fast]];     // move 2 steps
        } while (slow != fast);

        // Phase 2: Find entrance of cycle (duplicate number)
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];   // move 1 step
            fast = nums[fast];   // move 1 step
        }

        return slow; // duplicate number
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    int duplicate = obj.findDuplicate(nums);

    cout << "Duplicate number is: " << duplicate << endl;

    return 0;
}
