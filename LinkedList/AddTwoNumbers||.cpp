#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x = 0) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        stack<int> s1, s2;

        while (l1 != NULL) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != NULL) {
            s2.push(l2->val);
            s2.pop();
        }

        int sum = 0;
        int carry = 0;

        ListNode* ans = new ListNode();

        while (!s1.empty() || !s2.empty()) {

            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }

            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }

            ans->val = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(carry);
            newNode->next = ans;
            ans = newNode;

            sum = carry;
        }

        return carry == 0 ? ans->next : ans;
    }
};

ListNode* createList(vector<int> arr) {
    if (arr.empty()) return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    int n1, n2;

    cout << "Enter number of digits in list 1: ";
    cin >> n1;

    vector<int> arr1(n1);
    cout << "Enter digits of list 1: ";
    for (int i = 0; i < n1; i++)
        cin >> arr1[i];

    cout << "Enter number of digits in list 2: ";
    cin >> n2;

    vector<int> arr2(n2);
    cout << "Enter digits of list 2: ";
    for (int i = 0; i < n2; i++)
        cin >> arr2[i];

    ListNode* l1 = createList(arr1);
    ListNode* l2 = createList(arr2);

    Solution obj;
    ListNode* ans = obj.addTwoNumbers(l1, l2);

    cout << "\nResult: ";
    printList(ans);

    return 0;
}
