class Solution {
public:
    Node* connect(Node* root) {
        Node* curr = root;

        while (curr) {
            Node dummy(0);                 // head of the next level's chain
            Node* tail = &dummy;

            // Walk current level via next pointers (already established)
            for (Node* node = curr; node; node = node->next) {
                if (node->left)  { tail->next = node->left;  tail = tail->next; }
                if (node->right) { tail->next = node->right; tail = tail->next; }
            }

            curr = dummy.next;             // descend; NULL when no children left
        }
        return root;
    }
};