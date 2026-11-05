class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node* node = q.front(); q.pop();
                if (i < size - 1) node->next = q.front();   // link within level
                if (node->left) {
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
        return root;
    }
};