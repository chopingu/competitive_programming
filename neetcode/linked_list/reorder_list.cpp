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
        if(!head)
            return;

        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;
        }

        ListNode *prev = nullptr;
        ListNode *cur = slow->next;
        while(cur) {
            ListNode *tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        slow->next = nullptr;
        
        ListNode *le = head;
        ListNode *ri = prev;
        ListNode dummy(0);
        cur = &dummy;
        while(le && ri) {
            cur->next = le;
            le = le->next;
            cur = cur->next;

            cur->next = ri;
            ri = ri->next;
            cur = cur->next;
        }

        if(le) 
            cur->next = le;
        
        *head = *(dummy.next);
    }
};
