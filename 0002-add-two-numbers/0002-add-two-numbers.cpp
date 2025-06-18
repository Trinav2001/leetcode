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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        int carry = 0;

        while(l1 || l2 || carry) {
            int v1 = (l1) ? l1 -> val : 0;
            int v2 = (l2) ? l2 -> val : 0;

            int sum = v1 + v2 + carry;
            int value = sum % 10;
            carry = sum / 10;
            cur -> next = new ListNode(value);

            cur = cur -> next;

            l1 = (l1) ? l1 -> next : NULL;
            l2 = (l2) ? l2 -> next : NULL;
        }

        return dummy -> next;
    }
};