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
    bool hasCycle(ListNode *head) {
        ListNode *t1,*t2;
        t1=t2=head;
        while(t1!=NULL&&t2!=NULL){
            t1=t1->next;if(t1==NULL)return 0;
            t1=t1->next;if(t1==NULL)return 0;
            t2=t2->next;if(t2==NULL)return 0;
            if(t1==t2)return 1;
        }
        return 0;
    }
};
