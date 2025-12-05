#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* temp = head->next;
        head->next = swapPairs(head->next->next);
        temp->next = head;

        return temp;
    }
};

void printList(ListNode* head) {
    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* createList(int n) {
    if(n == 0) return NULL;

    int x;
    cin >> x;
    ListNode* head = new ListNode(x);
    ListNode* curr = head;

    for(int i = 1; i < n; i++) {
        cin >> x;
        curr->next = new ListNode(x);
        curr = curr->next;
    }

    return head;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values: ";
    ListNode* head = createList(n);

    Solution obj;
    ListNode* newHead = obj.swapPairs(head);

    cout << "After swapping pairs: ";
    printList(newHead);

    return 0;
}
