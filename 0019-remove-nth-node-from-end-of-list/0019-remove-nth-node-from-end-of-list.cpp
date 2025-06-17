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
        
        ListNode* left = dummy;
        ListNode* right = head;
        while(n > 0) {
            right = right -> next;
            n--;
        }

        while(right) {
            left = left -> next;
            right = right -> next;
        }

        left -> next = left -> next -> next;
        return dummy -> next;


        // int size = getSize(head);
        // int pos = size - n;
        // if(pos == 0) {
        //     ListNode* temp = head;
        //     head = head -> next;
        //     delete temp;
        //     return head;
        // }

        // ListNode* p = head;
        // while(pos > 1) {
        //     p = p -> next;
        //     pos--;
        // }

        // ListNode* q = p -> next;
        // p -> next = q -> next;
        // q -> next = NULL;

        // return head;
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