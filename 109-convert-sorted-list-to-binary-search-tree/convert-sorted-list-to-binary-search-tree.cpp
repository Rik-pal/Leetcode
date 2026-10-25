class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        for (ListNode* p = head; p; p = p->next) n++;

        this->head = head;
        return build(0, n - 1);
    }

private:
    ListNode* head;

    TreeNode* build(int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;

        // 1. Build left subtree first — consumes the first `mid - left` list nodes
        TreeNode* leftChild = build(left, mid - 1);

        // 2. Now head points at the in-order successor = current root
        TreeNode* root = new TreeNode(head->val);
        root->left = leftChild;
        head = head->next;

        // 3. Build right subtree from the remaining nodes
        root->right = build(mid + 1, right);

        return root;
    }
};