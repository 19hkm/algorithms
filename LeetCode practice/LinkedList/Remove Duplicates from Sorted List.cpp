// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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

//IMP: Recursive solution. Do not prefer to used this
// as if written for prod like env and higher value of n
// run time worst stack space is n. So could lead to stackOverflow  
class Solution {
public:
    ListNode* eraseDup(ListNode* head, int val){
        if(!head) return NULL;
        else if (head->val == val)
        {
            ListNode* nextNode = head->next;
            return eraseDup(nextNode, val);
        } else {
            head->next = eraseDup(head->next, head->val);
            return head;
        }
    } 
    ListNode* deleteDuplicates(ListNode* head) {
        return eraseDup(head, -101);
    }
};

// Prefer this kind of iterative solution
class Solution {
public: 
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        while(curr && curr->next){
            if(curr->val == curr->next->val)
                curr->next = curr->next->next;
            else
                curr = curr->next;
        }
        return head;
    }
};