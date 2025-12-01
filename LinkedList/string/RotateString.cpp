#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char firstChar = s[0];
            s.erase(s.begin());
            s.push_back(firstChar);
            if (s == goal) return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    cout << sol.rotateString("abcde", "cdeab") << endl;
    cout << sol.rotateString("abcde", "abced") << endl;
}
