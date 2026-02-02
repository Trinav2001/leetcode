/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {


        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        ListNode* nxt = head;

        int step = n;

        while (step--) {
            nxt = nxt -> next;
        }

        while (nxt)  {
            prev = prev -> next;
            nxt = nxt -> next;
        }

        
        prev -> next = prev -> next -> next;
        

        return dummy -> next;
        
    }
};