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
        int n = 0;
        ListNode *node = head;
        while(node) {
            n++;
            node = node->next;
        }

        vector<ListNode*> ends;
        ListNode *start = head;
        for(int i = 0; i < n / k; i++) {
            ListNode *prev = nullptr, *cur = start;
            for(int j = 0; j < k; j++) {
                ListNode *tmp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = tmp;
            }

            ends.push_back(prev);
            ends.push_back(start);
            start = cur;
        }
        ends.push_back(start);

        for(int i = 1; i < ends.size(); i += 2) 
            ends[i]->next = ends[i + 1];

        return ends[0];
    }
};
