#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')') count--;
            if (count != 0) ans.push_back(s[i]);
            if (s[i] == '(') count++;
        }
        return ans;
    }
};

int main() {
    string s;
    cout << "Enter parentheses string: ";
    cin >> s;

    Solution obj;
    string result = obj.removeOuterParentheses(s);

    cout << "After removing outer parentheses: " << result << endl;
    return 0;
}
