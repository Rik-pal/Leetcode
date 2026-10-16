class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);

        while (!q.empty()) {
            TreeNode* a = q.front(); q.pop();
            TreeNode* b = q.front(); q.pop();

            if (!a && !b) continue;       // Both null → match
            if (!a || !b) return false;   // One null → mismatch
            if (a->val != b->val) return false;

            // Push crossed pairs to preserve mirror comparison
            q.push(a->left);  q.push(b->right);
            q.push(a->right); q.push(b->left);
        }
        return true;
    }
};