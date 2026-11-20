/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        gain(root);
        return ans;
    }

private:
    int ans;

    // Best straight-path sum starting at this node and going downward
    int gain(TreeNode* node) {
        if (!node) return 0;

        // Ignore subtrees that would subtract value
        int left  = max(0, gain(node->left));
        int right = max(0, gain(node->right));

        // Best path whose "peak" (bend) is this node
        ans = max(ans, node->val + left + right);

        // Return best straight path upward (can't take both sides)
        return node->val + max(left, right);
    }
};