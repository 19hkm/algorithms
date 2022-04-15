// https://leetcode.com/problems/linked-list-cycle-ii/

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
    ListNode *detectCycle(ListNode *head) {
        ListNode *givenHead = head;
        if(!head) return NULL;
        ListNode *fastNode = head->next;
        while(fastNode && fastNode->next && fastNode!=head){
            head = head->next;
            fastNode = fastNode->next->next;
        }
        if(fastNode != head) return NULL;
        head = givenHead;
        fastNode = fastNode->next;
        while(head != fastNode){
            head = head->next;
            fastNode = fastNode->next;
        }
        return head;
    }
};