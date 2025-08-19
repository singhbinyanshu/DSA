#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        int maxcandi = 0;

        // step 1: find max candies
        for(int i=0; i<n; i++){
            maxcandi = max(maxcandi, candies[i]);
        }

        // step 2: check each kid
        vector<bool> result(n);
        for(int i=0; i<n; i++){
            if(candies[i] + extraCandies >= maxcandi){
                result[i] = true;
            } else {
                result[i] = false;
            }
        }
        return result;
    }
};

int main() {
    int n;
    cout << "Enter number of kids: ";
    cin >> n;

    vector<int> candies(n);
    cout << "Enter candies for each kid: ";
    for(int i=0; i<n; i++){
        cin >> candies[i];
    }

    int extraCandies;
    cout << "Enter extra candies: ";
    cin >> extraCandies;

    Solution sol;
    vector<bool> ans = sol.kidsWithCandies(candies, extraCandies);

    cout << "Result: ";
    for(int i=0; i<n; i++){
        if(ans[i]) cout << "true ";
        else cout << "false ";
    }
    cout << endl;

    return 0;
}
