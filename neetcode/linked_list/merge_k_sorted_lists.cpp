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
    ListNode *mergeLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode *node = &dummy;
        while(l1 && l2) {
            if(l1->val > l2->val)
                swap(l1, l2);

            node->next = l1;
            node = node->next;
            l1 = l1->next;
        }

        if(l1)
            node->next = l1;
        else if(l2)
            node->next = l2;
        
        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size()) 
            return 0;
        
        if(lists.size() == 1) 
            return lists[0];
        
        int mid = (lists.size() + 1) / 2;
        vector<ListNode*> le_lists, ri_lists;
        for(int i = 0; i < mid; i++)
            le_lists.push_back(lists[i]);

        for(int i = mid; i < lists.size(); i++) 
            ri_lists.push_back(lists[i]);

        ListNode *le = mergeKLists(le_lists);
        ListNode *ri = mergeKLists(ri_lists);
        return mergeLists(le, ri);
    }
};
