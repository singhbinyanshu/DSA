#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Recursive reverse function
ListNode* reverseList(ListNode* head) {
    // Base case
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Reverse the rest list
    ListNode* last = reverseList(head->next);

    // Reverse the current pointer
    head->next->next = head;
    head->next = NULL;

    return last;
}

// Function to print linked list
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
        cout << "Empty list." << endl;
        return 0;
    }

    cout << "Enter linked list values: ";
    int val;
    cin >> val;

    ListNode* head = new ListNode(val);
    ListNode* temp = head;

    for (int i = 1; i < n; i++) {
        cin >> val;
        temp->next = new ListNode(val);
        temp = temp->next;
    }

    cout << "Original List: ";
    printList(head);

    head = reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
