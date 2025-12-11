#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to detect cycle using Floyd's Algorithm
bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }
    return false;
}

// Function to create cycle at given position
void createCycle(ListNode* head, int pos) {
    if (pos < 0) return;

    ListNode* temp = head;
    ListNode* cycleNode = NULL;
    int index = 0;

    while (temp->next != NULL) {
        if (index == pos)
            cycleNode = temp;
        temp = temp->next;
        index++;
    }

    // Linking last node to cycleNode
    temp->next = cycleNode;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    if (n == 0) {
        cout << "No nodes in list." << endl;
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

    int pos;
    cout << "Enter position to create cycle (-1 for no cycle): ";
    cin >> pos;

    createCycle(head, pos);

    if (hasCycle(head))
        cout << "Cycle detected." << endl;
    else
        cout << "No cycle found." << endl;

    return 0;
}
