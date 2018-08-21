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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)  //空指针
            return head;
        ListNode *p=head;
        int size=0;
        while(head->next){
            head=head->next;
            size++;
        }
        head->next=p;
        size++;



        int div=k/size;
        int count=div*size-k>0?div*size-k:(div+1)*size-k;  //计算应该走的步数
        while(count-->0){
            p=p->next;

        }
        ListNode *tmp=p;
        while(tmp->next!=p&&tmp->next){
            tmp=tmp->next;
        }
        tmp->next=NULL;

        return p;
    }
};
