/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> oldToCopy;
        oldToCopy[NULL] = NULL;

        Node* current = head;
        while(current) {
            Node* copy = new Node(current -> val);
            oldToCopy[current] = copy;
            current = current -> next;
        }

        current = head;
        while(current) {
            Node* copy = oldToCopy[current];
            copy -> next = oldToCopy[current -> next];
            copy -> random = oldToCopy[current -> random];
            current = current -> next;
        }

        return oldToCopy[head];
    }
};