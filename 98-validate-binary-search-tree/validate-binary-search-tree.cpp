class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* prev = nullptr;
        TreeNode* curr = root;

        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top(); st.pop();
            if (prev && curr->val <= prev->val) return false;
            prev = curr;
            curr = curr->right;
        }
        return true;
    }
};