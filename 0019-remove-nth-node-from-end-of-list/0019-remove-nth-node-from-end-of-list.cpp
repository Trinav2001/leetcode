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
        int size = getSize(head);
        int pos = size - n;
        if(pos == 0) {
            ListNode* temp = head;
            head = head -> next;
            delete temp;
            return head;
        }
        
        ListNode* p = head;
        while(pos > 1) {
            p = p -> next;
            pos--;
        }

        ListNode* q = p -> next;
        p -> next = q -> next;
        q -> next = NULL;

        return head;
    }

    int getSize(ListNode* head) {
        int size = 0;
        while (head != nullptr) {
            size++;
            head = head->next;
        }
    return size;
    }
};