#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> count(26, 0);

        for (char &ch : s) {
            count[ch - 'a']++;
        }

        for (char &ch : t) {
            count[ch - 'a']--;
        }

        bool allZeros = all_of(begin(count), end(count), [](int element) {
            return element == 0;
        });

        return allZeros;
    }
};

int main() {
    Solution sol;
    cout << sol.isAnagram("listen", "silent") << endl; // 1
    cout << sol.isAnagram("rat", "car") << endl;       // 0
}
