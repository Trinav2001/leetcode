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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* groupPrev = dummy;

        while (true) {
            ListNode* kth = getKth(groupPrev, k);

            if (kth == NULL) {
                break;
            }

            ListNode* groupNext = kth -> next;
            ListNode* prev = kth -> next;
            ListNode* cur = groupPrev -> next;

            while (cur != groupNext) {
                ListNode* temp = cur -> next;
                cur -> next = prev;
                prev = cur;
                cur = temp;
            }

            ListNode* tmp = groupPrev -> next;
            groupPrev -> next = kth;
            groupPrev = tmp;
        }

        return dummy -> next;
    }

    ListNode* getKth(ListNode* cur, int k) {
        while(cur && k > 0) {
            cur = cur -> next;
            k--;
        }
        return cur;
    }
};