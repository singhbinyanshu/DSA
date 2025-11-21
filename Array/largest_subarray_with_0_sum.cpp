#include <bits/stdc++.h>
using namespace std;

int maxLengthOptimal(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> mpp;  // {prefixSum -> firstIndex}
    int sum = 0, maxi = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) {
            maxi = i + 1;  // पूरा subarray [0..i] का sum = 0
        }
        else if (mpp.find(sum) != mpp.end()) {
            maxi = max(maxi, i - mpp[sum]);
        }
        else {
            mpp[sum] = i;  // पहली बार ये sum आया है → index store करो
        }
    }
    return maxi;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nLength of Largest Subarray with Sum 0: " 
         << maxLengthOptimal(arr) << endl;

    return 0;
}
