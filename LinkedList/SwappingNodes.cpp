#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to find length of list
int findLength(ListNode* head){
    int l = 0;
    while(head != NULL){
        head = head->next;
        l++;
    }
    return l;
}

// Function to swap nodes
ListNode* swapNodes(ListNode* head, int k) {
    int L = findLength(head);

    // Find k-th node from start
    int k1 = k;
    ListNode* Node1 = head;
    while(k1 > 1){
        Node1 = Node1->next;
        k1--;
    }

    // Find k-th node from end
    int k2 = L - k + 1;
    ListNode* Node2 = head;
    while(k2 > 1){
        Node2 = Node2->next;
        k2--;
    }

    // Swap values
    swap(Node1->val, Node2->val);

    return head;
}

// Function to print the list
void printList(ListNode* head){
    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    if(n == 0){
        cout << "Empty list!" << endl;
        return 0;
    }

    cout << "Enter " << n << " values: ";
    int x;
    cin >> x;
    ListNode* head = new ListNode(x);
    ListNode* temp = head;

    for(int i = 1; i < n; i++){
        cin >> x;
        temp->next = new ListNode(x);
        temp = temp->next;
    }

    int k;
    cout << "Enter k: ";
    cin >> k;

    head = swapNodes(head, k);

    cout << "List after swapping: ";
    printList(head);

    return 0;
}
