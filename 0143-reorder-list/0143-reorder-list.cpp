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
        ListNode* slow;
        ListNode* fast;
        slow = head;
        fast = head -> next;

        // Finding the mid
        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        ListNode* second = slow -> next;
        slow -> next = NULL;

        // Reversing the second half of the list
        ListNode* prev = NULL;
        ListNode* temp;
        while(second) {
            temp = second -> next;
            second -> next = prev;
            prev = second;
            second = temp;
        }
        

        // Merging the two halves

        second = prev;
        ListNode* first = head;
        while(second) {
            ListNode* temp1 = first -> next;
            ListNode* temp2 = second -> next;
            first -> next = second;
            second -> next = temp1;
            first = temp1;
            second = temp2;
        }



    }
};
