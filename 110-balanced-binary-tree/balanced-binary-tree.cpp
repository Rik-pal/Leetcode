class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }

    // Returns height of subtree, or -1 if unbalanced anywhere inside
    int height(TreeNode* node) {
        if (!node) return 0;

        int left = height(node->left);
        if (left == -1) return -1;          // left subtree already unbalanced

        int right = height(node->right);
        if (right == -1) return -1;         // right subtree already unbalanced

        if (abs(left - right) > 1) return -1;  // current node violates balance

        return max(left, right) + 1;
    }
};