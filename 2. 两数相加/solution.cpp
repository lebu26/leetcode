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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* it1 = l1;
        ListNode* it2 = l2;
        ListNode* resHead = NULL;
        ListNode* resIt = resHead;
        int carrier = 0;
        while(it1 != NULL || it2 != NULL) {
            int a=0, b=0;
            if (it1 != NULL) {
                a = it1 -> val;
                it1 = it1 -> next;
            }
            if (it2 != NULL) {
                b = it2 -> val;
                it2 = it2 -> next;
            }
            int res = a + b + carrier;
            carrier = res >= 10? 1:0;
            res = res >= 10? res-10 : res;

            ListNode *n = new ListNode(res);
            if(resHead == NULL) {
                resHead = n;
                resIt = resHead;
            } else {
                resIt -> next = n;
                resIt = resIt -> next;
            }
        }
        if(carrier != 0) {
            ListNode *n = new ListNode(1);
            if(resHead == NULL) {
                resHead = n;
                resIt = resHead;
            } else {
                resIt -> next = n;
            }            
        }
        return resHead;
    }
};