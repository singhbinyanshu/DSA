#include <iostream>
#include<vector>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    // Merge two sorted linked lists (recursive)
    ListNode* mergeTwoSortedLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;

        if (list1->val <= list2->val) {
            list1->next = mergeTwoSortedLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoSortedLists(list2->next, list1);
            return list2;
        }
    }

    // Partition list into halves and merge
    ListNode* partitionAndMerge(int start, int end, vector<ListNode*>& lists) {
        if (start > end) return NULL;
        if (start == end) return lists[start];

        int mid = start + (end - start) / 2;

        ListNode* L1 = partitionAndMerge(start, mid, lists);
        ListNode* L2 = partitionAndMerge(mid + 1, end, lists);

        return mergeTwoSortedLists(L1, L2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0) return NULL;

        return partitionAndMerge(0, k - 1, lists);
    }
};

/// -------- Helper Functions --------

// Create linked list from vector
ListNode* buildList(vector<int>& arr) {
    if (arr.size() == 0) return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Print linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int k;
    cout << "Enter number of linked lists (k): ";
    cin >> k;

    vector<ListNode*> lists(k);

    for (int i = 0; i < k; i++) {
        int n;
        cout << "Enter size of list " << i + 1 << ": ";
        cin >> n;

        vector<int> arr(n);
        cout << "Enter elements of list " << i + 1 << " in sorted order:\n";

        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }

        lists[i] = buildList(arr);
    }

    Solution s;
    ListNode* result = s.mergeKLists(lists);

    cout << "\nMerged Sorted List:\n";
    printList(result);

    return 0;
}
