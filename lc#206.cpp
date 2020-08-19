/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 翻转列表，另一种方式是递归
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre=nullptr;
        ListNode *p=head;
        while(p)
        {
            ListNode* temp;
            temp = p->next;
            p->next=pre;
            pre=p;
            p=temp;
        }
        return pre;
    }
};