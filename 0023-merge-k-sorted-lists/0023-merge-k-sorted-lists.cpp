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
  private:
ListNode* mergeLists(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;

    while(l1 && l2) {
        if(l1 -> val < l2 -> val) {
            cur -> next = l1;
            l1 = l1 -> next;
        }
        else {
            cur -> next = l2;
            l2 = l2 -> next;
        }
        cur = cur -> next;
    }

    if(l1) {
        cur -> next = l1;
    }
    if(l2) {
        cur -> next = l2;
    }

    return dummy -> next;
}

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) {
            return NULL;
        }

        while(lists.size() > 1) {
            vector<ListNode*> mergedLists;

            for(int i = 0; i < lists.size(); i += 2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = (i + 1 < lists.size()) ? lists[i + 1] : NULL;
                mergedLists.push_back(mergeLists(l1, l2));
                
            }
            lists = mergedLists;
        }
        return lists[0];
    }

};