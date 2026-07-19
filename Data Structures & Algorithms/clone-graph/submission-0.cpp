class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* dfs(Node* node) {
        if (node == NULL)
            return NULL;

        if (mp.count(node))
            return mp[node];

        Node* clone = new Node(node->val);
        mp[node] = clone;

        for (auto nei : node->neighbors) {
            clone->neighbors.push_back(dfs(nei));
        }

        return clone;
    }

    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};