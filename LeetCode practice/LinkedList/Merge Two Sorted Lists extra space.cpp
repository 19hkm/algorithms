// https://leetcode.com/problems/merge-two-sorted-lists/

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
    
    void addAll(TreeNode** &head, TreeNode* list){
        while(list){
            (*head)->next
        }
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyHead = new ListNode(-101);
        ListNode* head = dummyHead;
        while(list1 && list2){
            if(list1->val < list2->val) {
                head->next = new ListNode(list1->val);
                head = head->next;
                list1 = list1->next;
            } else{
                head->next = new ListNode(list2->val);
                head = head->next;
                list2 = list2->next;
            }
        }
        while(list1){
            head->next= new ListNode(list1->val);
            list1 = list1->next;
            head = head->next;
        }
        
        while(list2){
            head->next= new ListNode(list2->val);
            list2 = list2->next;
            head = head->next;
        }
        return dummyHead->next;
    }
};
