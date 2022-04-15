// https://leetcode.com/problems/linked-list-cycle/

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
        if(!head)  return false;
        ListNode *fastNode = head->next;
        while(fastNode && fastNode->next && head != fastNode){
            head = head->next;
            fastNode = fastNode->next->next;
        }
        return (fastNode && head==fastNode);
        
    }
};