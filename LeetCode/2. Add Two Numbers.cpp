/*
Cautions
1. Abs function doesn't work with size_t type.
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <vector>
#include <stdlib.h>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v1, v2;
        for(ListNode* it = l1; it != NULL; it=it->next)
            v1.push_back(it->val);
        for(ListNode* it = l2; it != NULL; it=it->next)
            v2.push_back(it->val);
        
        int len = v1.size() - v2.size();
        if(len < 0)
            len *= -1;
        for(int i=0; i<len; i++)
            if(v1.size() > v2.size())
                v2.push_back(0);
            else
                v1.push_back(0);
        
        v1.push_back(0);
        v2.push_back(0);
        
        ListNode* l = NULL;
        for(int i=0, prev=0; i<v1.size(); i++)
            prev = append(&l, v1[i], v2[i], prev);

        ListNode* p = l;
        ListNode* pp = NULL;
        for(; p->next != NULL; pp=p, p=p->next);
        if(p->val == 0){
            delete p;
            pp->next = NULL;
        }            
        
        return l;
    }
    
    int append(ListNode** l, int a, int b, int prev){
        if(*l == NULL)
            *l = new ListNode((a + b + prev) % 10);
        else{
            ListNode* p = *l;
            while(p->next) p = p->next;
            p->next = new ListNode((a + b + prev) % 10);
        }

        if(a + b + prev >= 10)
            return 1;
        return 0;
    }
};
