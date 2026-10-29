class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(root, targetSum, path, result);
        return result;
    }

private:
    void dfs(TreeNode* node, int target, vector<int>& path,
             vector<vector<int>>& result) {
        if (!node) return;

        path.push_back(node->val);
        target -= node->val;

        if (!node->left && !node->right && target == 0) {
            result.push_back(path);      // copy the valid path
        } else {
            dfs(node->left,  target, path, result);
            dfs(node->right, target, path, result);
        }

        path.pop_back();                 // backtrack before returning
    }
};