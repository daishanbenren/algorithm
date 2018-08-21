//题目：找到两个链表相交的节点

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int getLength(ListNode *list){
        int count=0;
        ListNode *p=list;
        while(p){
             count++;
            p=p->next;
        }
           
        
        return count;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA||!headB)
            return NULL;
        int lenA=getLength(headA);
        int lenB=getLength(headB);
        
        int div=lenA>lenB?lenA-lenB:lenB-lenA;
        while(lenA>lenB&&div>0){
            headA=headA->next;
            div--;
        }
         while(lenB>lenA&&div>0){
            headB=headB->next;
             div--;
        }
        
        while(headA!=headB&&headA&&headB){
            headA=headA->next;
            headB=headB->next;
            
        }
        
        return headA;
    }
};
