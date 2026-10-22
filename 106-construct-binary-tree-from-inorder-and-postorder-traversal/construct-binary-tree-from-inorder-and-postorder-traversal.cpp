#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)
            inorderIndex[inorder[i]] = i;

        postIdx = postorder.size() - 1;  // pointer into postorder (from the end)
        return build(postorder, 0, inorder.size() - 1);
    }

private:
    unordered_map<int, int> inorderIndex;
    int postIdx;

    TreeNode* build(vector<int>& postorder, int inLeft, int inRight) {
        if (inLeft > inRight) return nullptr;

        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);

        int mid = inorderIndex[rootVal];  // root's position in inorder

        // Build RIGHT subtree first (reverse postorder: root, right, left)
        root->right = build(postorder, mid + 1, inRight);
        root->left  = build(postorder, inLeft, mid - 1);

        return root;
    }
};