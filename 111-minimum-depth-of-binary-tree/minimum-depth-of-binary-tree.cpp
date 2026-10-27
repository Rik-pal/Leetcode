

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;

        while (!q.empty()) {
            depth++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); q.pop();

                // First leaf found = shallowest leaf, done
                if (!node->left && !node->right)
                    return depth;

                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return depth;  // unreachable for a non-empty tree
    }
};