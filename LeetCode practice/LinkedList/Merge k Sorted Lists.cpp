// Merge k Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/submissions/

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

#define PQ priority_queue
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = NULL, *curr=NULL;
        PQ<tuple<int, ListNode*>> pq;
        
        int n= lists.size();
        for(int i=0; i<n; i++) {
            auto node = lists[i];
            if(node) {
                pq.push({-(node->val), node});
            }
        }
        
        while(!pq.empty()) {
            int val;
            ListNode *pqTop;
            tie(val, pqTop) = pq.top();
            pq.pop();
            
            if(!head) {
                head = pqTop;
                curr = head;
            } else {
                curr->next = pqTop;
                curr = pqTop;
            }
            
            if(curr->next) {
                pq.push({-(curr->next->val), curr->next});
                curr->next = NULL;
            }
        }
        
        return head;
    }
};