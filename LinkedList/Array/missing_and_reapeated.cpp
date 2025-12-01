#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
       vector<int> ans;
       unordered_set<int> s;  
       int n = grid.size();
       int a, b;
       int expSum = 0, actualSum = 0;

       for (int i = 0; i < n; i++) {
           for (int j = 0; j < n; j++) {
               actualSum += grid[i][j];
               if (s.find(grid[i][j]) != s.end()) {
                   a = grid[i][j];
                   ans.push_back(a);
               }
               s.insert(grid[i][j]);
           }
       }

       expSum = (n * n) * (n * n + 1) / 2;
       b = expSum + a - actualSum;
       ans.push_back(b);
       return ans;
    }
};

int main() {
    int n;
    cout << "Enter size of matrix (n): ";
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    cout << "Enter elements of the matrix (" << n * n << " values):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    vector<int> ans = obj.findMissingAndRepeatedValues(grid);

    cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;
    return 0;
}
