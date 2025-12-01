#include <iostream>
#include <vector>
using namespace std;

// ---------------------- Linked List Node ----------------------
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int data) {
        val = data;
        next = NULL;
    }
};

// ---------------------- Tree Node ----------------------
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        val = data;
        left = NULL;
        right = NULL;
    }
};

// ---------------------- Solution Class ----------------------
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {

        if (!head)
            return NULL;

        if (!head->next)
            return new TreeNode(head->val);

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* slow_prev = NULL;

        // Find middle node
        while (fast != NULL && fast->next != NULL) {
            slow_prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow = middle
        TreeNode* root = new TreeNode(slow->val);

        // break list
        slow_prev->next = NULL;

        // left and right recursive calls
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};

// ---------------------- Inorder Traversal ----------------------
void inorder(TreeNode* root) {
    if (!root) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// ---------------------- Create Linked List ----------------------
ListNode* createList(vector<int> arr) {
    if (arr.size() == 0) return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

// ---------------------- MAIN FUNCTION ----------------------
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter sorted linked list elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Create linked list
    ListNode* head = createList(arr);

    // Convert to BST
    Solution obj;
    TreeNode* root = obj.sortedListToBST(head);

    // Print inorder traversal
    cout << "Inorder Traversal of BST: ";
    inorder(root);

    return 0;
}
