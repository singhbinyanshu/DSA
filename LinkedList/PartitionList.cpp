#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

// Linked List node structure
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode* small = new ListNode(0);
        ListNode* large = new ListNode(0);

        ListNode* smallP = small;
        ListNode* largeP = large;

        while (head != NULL) {
            if (head->val < x) {
                smallP->next = head;
                smallP = smallP->next;
            } else {
                largeP->next = head;
                largeP = largeP->next;
            }
            head = head->next;
        }

        smallP->next = large->next;
        largeP->next = NULL;

        return small->next;
    }
};

// Print Linked List
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    if (n == 0) {
        cout << "Empty list!" << endl;
        return 0;
    }

    cout << "Enter the elements: ";
    int val;
    cin >> val;

    ListNode* head = new ListNode(val);
    ListNode* temp = head;

    // take input for remaining nodes
    for (int i = 1; i < n; i++) {
        cin >> val;
        temp->next = new ListNode(val);
        temp = temp->next;
    }

    int x;
    cout << "Enter x: ";
    cin >> x;

    Solution s;
    ListNode* newHead = s.partition(head, x);

    cout << "Partitioned List: ";
    printList(newHead);

    return 0;
}
