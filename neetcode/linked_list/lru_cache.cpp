#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    int key;

    Node *prev;
    Node *next;

    Node(int val, int key) : val(val), key(key), prev(0), next(0) {}
};

class LRUCache {
    int cap;
    unordered_map<int, Node*> mp;
    Node *left, *right;

    void rem(Node *node) {
        Node *prev = node->prev;
        Node *next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void ins(Node *node) {
        Node *prev = right->prev;
        prev->next = node;
        right->prev = node;
        node->next = right;
        node->prev = prev;
    }

public:
    LRUCache(int capacity) : cap(capacity) {
        left = new Node(-1, -1);
        right = new Node(-1, -1);
        left->next = right;
        right->prev = left;
    }

    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;

        Node *node = mp[key];
        rem(node);
        ins(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            Node *node = mp[key];
            rem(node);
            ins(node);
            node->val = value;
            return;
        }

        if(mp.size() == cap) {
            Node *node = left->next;
            mp.erase(node->key);
            rem(node);
        }

        Node *node = new Node(value, key);
        ins(node);
        mp[key] = node;
    }
};
