#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        // Same LeetCode logic
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Linked list size: ";
    cin >> n;

    if (n < 2) {
        cout << "List must have at least 2 nodes for this delete method.\n";
        return 0;
    }

    cout << "Enter " << n << " values: ";
    int x;
    cin >> x;

    ListNode* head = new ListNode(x);
    ListNode* temp = head;

    // Create linked list
    for (int i = 1; i < n; i++) {
        cin >> x;
        temp->next = new ListNode(x);
        temp = temp->next;
    }

    cout << "Enter value to delete: ";
    int del;
    cin >> del;

    // Find the node which has value equal to del
    ListNode* curr = head;
    while (curr != NULL && curr->next != NULL && curr->val != del) {
        curr = curr->next;
    }

    // Validation
    if (curr == NULL || curr->next == NULL) {
        cout << "Cannot delete this node using this method (either last node or not found).\n";
        return 0;
    }

    // Call deleteNode
    Solution s;
    s.deleteNode(curr);

    cout << "Updated Linked List: ";
    printList(head);

    return 0;
}
