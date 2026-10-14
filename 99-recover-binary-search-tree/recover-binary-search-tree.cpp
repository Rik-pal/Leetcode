class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;
        inorder(root, prev, first, second);
        swap(first->val, second->val);
    }

private:
    void inorder(TreeNode* node, TreeNode*& prev,
                 TreeNode*& first, TreeNode*& second) {
        if (!node) return;

        inorder(node->left, prev, first, second);

        if (prev && prev->val > node->val) {
            if (!first) first = prev;        // capture the larger node once
            second = node;                   // keep updating the smaller node
        }
        prev = node;

        inorder(node->right, prev, first, second);
    }
};