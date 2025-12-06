#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> vec;
        ListNode* curr = head;

        while (curr != NULL) {
            vec.push_back(curr->val);
            curr = curr->next;
        }

        int result = 0;
        int i = 0, j = vec.size() - 1;

        while (i < j) {
            result = max(result, vec[i] + vec[j]);
            i++;
            j--;
        }
        return result;
    }
};

int main() {
    int n;
    cout << "Enter number of nodes (even number): ";
    cin >> n;

    ListNode* head = NULL;
    ListNode* tail = NULL;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        ListNode* newNode = new ListNode(x);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Solution obj;
    int ans = obj.pairSum(head);

    cout << "Maximum Twin Sum = " << ans << endl;

    return 0;
}
