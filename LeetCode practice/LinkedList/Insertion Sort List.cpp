// https://www.interviewbit.com/problems/insertion-sort-list/#_=_

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode*  insertToHead(ListNode* head, ListNode* curr) {
    if(!head) {
        return curr;
    } else if(head->val >= curr->val) {
        curr->next = head;
        return curr;
    } else {
        head->next =  insertToHead(head->next, curr);
        return head;
    }
}
 
ListNode* Solution::insertionSortList(ListNode* A) {   
    if(!A){
        return A;
    }
    ListNode* head = NULL, *curr = A;
    while(curr) {
        ListNode* nextNode = curr->next;
        curr->next = NULL;
        head = insertToHead(head, curr);
        curr = nextNode;   
    }
    return head;
}
