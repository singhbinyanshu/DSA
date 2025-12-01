#include <iostream>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();        //rows
    int n = matrix[0].size();     //columns

    int dir = 0;

    /*
        dir = 0 : left to right
        dir = 1 : top to down
        dir = 2 : right to left
        dir = 3 : down to top
    */

    int top = 0, down = m - 1;
    int left = 0, right = n - 1;

    vector<int> result;

    while (top <= down && left <= right) {

        if (dir == 0) {
            //left to right
            //constant : row (top)
            for (int i = left; i <= right; i++) {
                result.push_back(matrix[top][i]);
            }
            top++;
        }

        if (dir == 1) {
            //top to down
            //constant : column (right)
            for (int i = top; i <= down; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;
        }

        if (dir == 2) {
            //right to left
            //constant : row (down)
            for (int i = right; i >= left; i--) {
                result.push_back(matrix[down][i]);
            }
            down--;
        }

        if (dir == 3) {
            //down to top
            //constant : col (left)
            for (int i = down; i >= top; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }

        dir = (dir + 1) % 4;
    }

    return result;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<int> ans = spiralOrder(matrix);

    for (int num : ans) {
        cout << num << " ";
    }
    return 0;
}
