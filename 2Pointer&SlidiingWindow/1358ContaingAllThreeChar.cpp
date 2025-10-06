#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int a = 0, b = 0, c = 0;
        int i = 0, j = 0;
        int count = 0;

        while (j < n) {
            // include s[j] in window
            if (s[j] == 'a') a++;
            if (s[j] == 'b') b++;
            if (s[j] == 'c') c++;

            // jab sab char aa jaayein
            while (a >= 1 && b >= 1 && c >= 1) {
                count += (n - j);  // all substrings from i..j to i..n-1 are valid

                // window chhoti karo
                if (s[i] == 'a') a--;
                if (s[i] == 'b') b--;
                if (s[i] == 'c') c--;
                i++;
            }

            j++;
        }

        return count;
    }
};

int main() {
    Solution obj;
    string s = "abcabc";
    cout << obj.numberOfSubstrings(s);
    return 0;
}
