#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Map value -> index in inorder for O(1) root lookup
        for (int i = 0; i < inorder.size(); i++)
            inorderIndex[inorder[i]] = i;

        preIdx = 0;  // pointer into preorder
        return build(preorder, 0, inorder.size() - 1);
    }

private:
    unordered_map<int, int> inorderIndex;
    int preIdx;

    TreeNode* build(vector<int>& preorder, int inLeft, int inRight) {
        if (inLeft > inRight) return nullptr;

        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);

        int mid = inorderIndex[rootVal];  // root's position in inorder

        // Build left subtree first (preorder: root, left, right)
        root->left  = build(preorder, inLeft, mid - 1);
        root->right = build(preorder, mid + 1, inRight);

        return root;
    }
};