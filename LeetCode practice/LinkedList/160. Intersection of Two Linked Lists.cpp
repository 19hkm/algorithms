// https://leetcode.com/problems/intersection-of-two-linked-lists/

// METHOD 1: O(m+n) extra space
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        set<ListNode*> myNodeSet;
        while(headA){
            myNodeSet.insert(headA);
            headA = headA ->next;
        }
        while(headB){
            if(myNodeSet.find(headB)==myNodeSet.end())
                headB = headB ->next;
            else return headB;
        }
        return NULL;
    }
};


// METHOD 2: no extra space O(1). Use of loop finding tech in __INCLUDE_LEVEL__
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
    
    ListNode* createLoopAndReturnTail(ListNode *head){
        ListNode *curr= head;
        while(curr && curr->next)  curr = curr->next;
        curr->next = head;
        return curr;
    }
    
    ListNode* findHeadofLoop(ListNode *head){
        ListNode *headA = head;
        ListNode *fastHead = head->next;
        while(fastHead && fastHead->next && fastHead!=head){
            fastHead = fastHead->next->next;
            head = head->next;
        }
        if(!fastHead || !fastHead->next)
            return NULL;
        fastHead = fastHead->next;
        head =headA;
        while(head != fastHead){
            head = head->next;
            fastHead = fastHead->next;
        }
        return head;
    }
    
    ListNode* findInChain(ListNode *headA, ListNode *headB){
        while(headB){
            if(headB==headA)    return headA;
            headB = headB->next;
        }
        return NULL;
    }
    
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB ) return NULL;
        else if(headA == headB) return headA;
        else if(!headA->next) return findInChain(headA, headB);
        else if (!headB->next) return findInChain(headB, headA);
        
        ListNode* tailA = createLoopAndReturnTail(headA);
        ListNode* loopHeadB = findHeadofLoop(headB);
        tailA->next = NULL;
        
        return loopHeadB;
    }
};


//METHOD 3: amazing amazing solution
// https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/49785/Java-solution-without-knowing-the-difference-in-len!
class Solution {
public:
    
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB ) return NULL;
        
        ListNode *a = headA;
        ListNode *b = headB;
        
        while(a != b){
            a = !a?  headB : a->next;
            b = !b? headA : b->next;
        }
        return a;
    }
};