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
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* p = slow -> next;
        slow -> next = NULL;

        ListNode* r= NULL;
        ListNode* q = NULL;

        while (p) {
            r = q;
            q = p;
            p = p -> next;
            q -> next = r;
            
        }

        ListNode* second = q;
        ListNode* first = head;
        while (second) {
            ListNode* temp1 = first -> next;
            ListNode* temp2 = second -> next;

            first -> next = second;
            second -> next = temp1;
            first = temp1;
            second = temp2;

        }
        
    }
};