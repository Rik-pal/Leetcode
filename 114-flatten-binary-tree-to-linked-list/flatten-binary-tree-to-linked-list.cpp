class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        flatten(root->right);          // reverse pre-order: right first
        flatten(root->left);
        root->right = prev;
        root->left  = nullptr;
        prev = root;
    }
private:
    TreeNode* prev = nullptr;
};