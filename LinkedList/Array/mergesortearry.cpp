#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;        // nums1 ka last valid element
    int j = n - 1;        // nums2 ka last element
    int k = m + n - 1;    // nums1 ka last index (total space)

    // Backwards fill
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }

    // Agar nums2 me kuch bacha ho
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {3, 4, 5};

    merge(nums1, 3, nums2, 3);

    for (int num : nums1) cout << num << " ";
}
