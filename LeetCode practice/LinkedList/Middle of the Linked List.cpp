//https://leetcode.com/problems/middle-of-the-linked-list/submissions/

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
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* doubleSpeedNode = head;
        while(doubleSpeedNode && doubleSpeedNode->next){
            doubleSpeedNode = doubleSpeedNode->next->next;
            head = head ->next;
        }
        return head;
    }
};