#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> rotated(n, vector<int>(m)); 

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rotated[j][m - 1 - i] = matrix[i][j];
            }
        }
        


        matrix = rotated;
    }
};

int main() {
    int m, n;
    cout << "Enter number of rows (m): ";
    cin >> m;
    cout << "Enter number of columns (n): ";
    cin >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    cout << "Enter the matrix elements:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    Solution obj;
    obj.rotate(matrix);

    cout << "Rotated Matrix:\n";
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
