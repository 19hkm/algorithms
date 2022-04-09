// Merge Two Sorted Lists - constant extra space
// https://leetcode.com/problems/merge-two-sorted-lists/submissions/

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
    
    ListNode* getNewListHead(ListNode* head, ListNode* list){
        ListNode* temp = list;
        ListNode* newListHead = list->next;
        temp->next = NULL;
        head->next = temp;
        return newListHead;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyHead = new ListNode(-101);
        ListNode* head = dummyHead;
        while(list1 && list2){
            if(list1->val < list2->val)
                list1 = getNewListHead(head, list1);
            else
                list2 = getNewListHead(head, list2);
            head = head->next;
        }
        
        while(list1){
            list1 = getNewListHead(head, list1);
            head = head->next;
        }
        
        while(list2){
            list2 = getNewListHead(head, list2);
            head = head->next;
        }
        return dummyHead->next;
    }
};