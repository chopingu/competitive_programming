/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;

        Node *head_nw = new Node(head->val);

        map<Node*, Node*> mp;
        mp[head] = head_nw;

        Node *cur1 = head->next;
        Node *cur2 = head_nw;
        while(cur1) {
            Node *node_nw = new Node(cur1->val);
            cur2->next = node_nw;

            cur2 = cur2->next;
            mp[cur1] = cur2;
            cur1 = cur1->next;
        }

        Node *cur = head;
        while(cur) {
            mp[cur]->random = mp[cur->random];
            cur = cur->next;
        }

        return head_nw;
    }
};
