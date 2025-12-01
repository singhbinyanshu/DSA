#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);

        // Count frequency of lowercase and uppercase separately
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a') {
                lower[s[i] - 'a']++; // index for lowercase
            } else {
                upper[s[i] - 'A']++; // index for uppercase
            }
        }

        int count = 0;
        bool odd = 0;

        // Build longest palindrome
        for (int i = 0; i < 26; i++) {
            if (lower[i] % 2 == 0) {
                count += lower[i];
            } else {
                count += lower[i] - 1;
                odd = 1;
            }

            if (upper[i] % 2 == 0) {
                count += upper[i];
            } else {
                count += upper[i] - 1;
                odd = 1;
            }
        }

        return count + odd; // add 1 if any odd count exists
    }
};

int main() {
    Solution sol;

    string s;
    cout << "Enter a string: ";
    cin >> s;

    int ans = sol.longestPalindrome(s);
    cout << "Longest Palindrome Length: " << ans << endl;

    return 0;
}
