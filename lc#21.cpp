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
// 合并两个有序链表
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p,*head;
        p=nullptr;
        if(l1||l2) p = new ListNode();
        head = p;
        while(l1&&l2){
            if(l1->val<l2->val){
                p->val=l1->val;
                p->next=new ListNode();
                p=p->next;
                l1=l1->next;
            } else{
                p->val=l2->val;
                p->next=new ListNode();
                p=p->next;
                l2=l2->next;
            }
        }
        while(l1){
            p->val=l1->val;
            l1=l1->next;
            if(l1) {p->next=new ListNode();p=p->next;}
        }
        while(l2){
            p->val=l2->val;
            l2=l2->next;
            if(l2) {p->next=new ListNode();p=p->next;}
        }
        return head;
    }
};