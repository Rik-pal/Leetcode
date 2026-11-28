class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        return dfs(node);
    }

private:
    unordered_map<Node*, Node*> copies;

    Node* dfs(Node* node) {
        if (copies.count(node)) return copies[node];

        Node* clone = new Node(node->val);
        copies[node] = clone;

        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbor));
        }
        return clone;
    }
};