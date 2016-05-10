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
    ListNode* reverseList(ListNode* head) {
        ListNode* now=NULL;
        for(ListNode* it=head;it;it=it->next){
            ListNode* t=new ListNode(it->val);
            t->next=now;
            now=t;
        }
        return now;
    }
};
