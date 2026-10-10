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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return build(1, n);
    }

private:
    // Generate all BSTs using values in [lo, hi]
    vector<TreeNode*> build(int lo, int hi) {
        if (lo > hi) return {nullptr};   // Empty tree is a valid subtree

        vector<TreeNode*> trees;
        for (int root = lo; root <= hi; ++root) {
            vector<TreeNode*> lefts  = build(lo, root - 1);
            vector<TreeNode*> rights = build(root + 1, hi);

            for (TreeNode* l : lefts)
                for (TreeNode* r : rights)
                    trees.push_back(new TreeNode(root, l, r));
        }
        return trees;
    }
};