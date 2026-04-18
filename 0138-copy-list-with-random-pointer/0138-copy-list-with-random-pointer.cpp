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

        Node* cur = head;
        while(cur) {
            Node* cp = new Node(cur -> val);
            oldToCopy[cur] = cp;
            cur = cur -> next;
        }

        cur = head;
        while (cur) {
            Node* node = oldToCopy[cur];
            node -> next = oldToCopy[cur -> next];
            node -> random = oldToCopy[cur -> random];
            cur = cur -> next;
        }

        return oldToCopy[head];
        
    }
};