class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        dfs(root, 0, result);
        return result;
    }

private:
    void dfs(TreeNode* node, int depth, vector<vector<int>>& result) {
        if (!node) return;
        if (depth == result.size())       // First node at this depth
            result.push_back({});
        result[depth].push_back(node->val);
        dfs(node->left,  depth + 1, result);
        dfs(node->right, depth + 1, result);
    }
};