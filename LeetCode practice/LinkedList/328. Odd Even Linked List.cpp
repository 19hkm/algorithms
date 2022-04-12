// https://leetcode.com/problems/odd-even-linked-list/submissions/

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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddHead = new ListNode(1e6+1);
        ListNode* evenHead = new ListNode(1e6+2);
        ListNode *oddCurrent = oddHead, *evenCurrent = evenHead;
        int count =1;
        while(head){
            if(count%2){
                oddCurrent->next = head;
                head = head->next;
                oddCurrent = oddCurrent->next;
                oddCurrent->next = NULL;
            } else {
                evenCurrent->next = head;
                head = head->next;
                evenCurrent = evenCurrent->next;
                evenCurrent->next = NULL;
            } 
            count++;
        }
        oddCurrent->next = evenHead->next;
        return oddHead->next;
    }
};