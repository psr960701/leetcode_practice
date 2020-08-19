/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

// 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

// 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p,*head;
        p = new ListNode();
        head = p;
        int jinwei=0;
        while(l1&&l2){
            p->val=(l1->val+l2->val+jinwei)%10;
            jinwei=(l1->val+l2->val+jinwei)/10;
            l1=l1->next;
            l2=l2->next;
            if(l1||l2) {
                p->next = new ListNode();
                p=p->next;
            }
        }
        while(l1){
            p->val=(l1->val+jinwei)%10;
            jinwei=(l1->val+jinwei)/10;
            l1=l1->next;
            if(l1) {
                p->next=new ListNode();
                p=p->next;
            }
        }
        while(l2){
            p->val=(l2->val+jinwei)%10;
            jinwei=(l2->val+jinwei)/10;
            l2=l2->next;
            if(l2) {
                p->next=new ListNode();
                p=p->next;
            }
        }
        if (jinwei){
            p->next=new ListNode();
            p=p->next;
            p->val=jinwei;
        }
        return head;
    }
};