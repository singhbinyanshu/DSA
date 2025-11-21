#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = n * n;
        
        vector<int> freq(N + 1, 0);  // frequency array (1..n^2)
        
        // count frequency
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                freq[grid[i][j]]++;
            }
        }
        
        int repeated = -1, missing = -1;
        
        for (int i = 1; i <= N; i++) {
            if (freq[i] == 2) repeated = i;
            if (freq[i] == 0) missing = i;
        }
        
        return {repeated, missing};
    }
};

int main() {
    int n;
    cout << "Enter size of matrix (n): ";
    cin >> n;
    
    vector<vector<int>> grid(n, vector<int>(n));
    
    cout << "Enter elements of the matrix (" << n*n << " values):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    
    Solution obj;
    vector<int> ans = obj.findMissingAndRepeatedValues(grid);
    
    cout << "Repeated: " << ans[0] << ", Missing: " << ans[1] << endl;
    return 0;
}
