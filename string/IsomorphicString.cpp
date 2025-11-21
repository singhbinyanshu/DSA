#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1;  // map from s -> t
        unordered_map<char, char> mp2;  // map from t -> s

        int m = s.length();
        for (int i = 0; i < m; i++) {
            char ch1 = s[i];
            char ch2 = t[i];

            // If mapping already exists but does not match → fail
            if ((mp1.find(ch1) != mp1.end() && mp1[ch1] != ch2) ||
                (mp2.find(ch2) != mp2.end() && mp2[ch2] != ch1)) {
                return false;
            }

            // Otherwise, add mapping both ways
            mp1[ch1] = ch2;
            mp2[ch2] = ch1;
        }
        return true;
    }
};

int main() {
    Solution sol;
    string s, t;

    cout << "Enter first string: ";
    cin >> s;

    cout << "Enter second string: ";
    cin >> t;

    bool ans = sol.isIsomorphic(s, t);
    if (ans)
        cout << "The strings are Isomorphic ✅" << endl;
    else
        cout << "The strings are NOT Isomorphic ❌" << endl;

    return 0;
}
