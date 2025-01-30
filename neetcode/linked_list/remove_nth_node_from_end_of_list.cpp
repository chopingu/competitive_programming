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
        int len = 0;
        ListNode *node = head;
        while(node) {
            len++;
            node = node->next;
        }

        node = head;
        for(int i = 0; i < len - n - 1; i++) 
            node = node->next;

        if(!n) 
            node->next = nullptr;
        else if(n == len)
            head = head->next;
        else 
            node->next = node->next->next;

        return head;
    }
};
