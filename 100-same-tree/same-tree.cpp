class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> qp, qq;
        qp.push(p); qq.push(q);

        while (!qp.empty() && !qq.empty()) {
            TreeNode* a = qp.front(); qp.pop();
            TreeNode* b = qq.front(); qq.pop();

            if (!a && !b) continue;         // Both null → match, move on
            if (!a || !b) return false;     // One null → mismatch
            if (a->val != b->val) return false;

            qp.push(a->left);  qp.push(a->right);
            qq.push(b->left);  qq.push(b->right);
        }
        return qp.empty() && qq.empty();    // Should always be equal size anyway
    }
};