/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* begin,ListNode *end){
        ListNode *tmp=new ListNode(0);
        ListNode *p=begin;
        while(begin!=end){
            begin=begin->next;
            p->next=tmp->next;
            tmp->next=p;
            p=begin;
        }
        end->next=tmp->next;
        tmp->next=end;
        
        return tmp->next;
        
    };
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *p_head=head;
        ListNode *n_head=head;
        ListNode *tail=head;
        ListNode *after_tail=head;
        int div=n-m;
        while(--m>1){
            p_head=p_head->next;
        }
        if(m==1)
            n_head=p_head->next;
        tail=n_head;
        while(--div>=0){
            tail=tail->next;
            
        }
        after_tail=tail->next;
        
        //reverse
        ListNode * new_list=reverse(n_head,tail);
        if(m==1)
            p_head->next=new_list;
        else
            head=new_list;
            
        while(new_list->next)
            new_list=new_list->next;
        new_list->next=after_tail;
     
        return head;
    }
     
    
};