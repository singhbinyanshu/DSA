#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int count = 0;     // current depth
        int maxCount = 0;  // maximum depth
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                count++;
                maxCount = max(maxCount, count); // using max function
            } 
            else if (s[i] == ')') {
                count--;
            }
        }
        return maxCount;
    }
};

int main() {
    Solution sol;
    
    string s;
    cout << "Enter string: ";
    cin >> s;

    cout << "Maximum Depth = " << sol.maxDepth(s) << endl;

    return 0;
}
