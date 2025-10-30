/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return node;

        unordered_map<Node*, Node*> map;
        Node* newNode = DFS(map, node);

        return newNode;
        
        
    }

    Node* DFS (unordered_map<Node*, Node*>& map, Node* node) {
        if (map[node]) {
            return map[node];
        }

        Node* copy = new Node;
        copy -> val = node -> val;
        map[node] = copy;

        for (auto& nei : node -> neighbors) {
            copy -> neighbors.push_back(DFS(map, nei));
        }

        return copy;
    }
};