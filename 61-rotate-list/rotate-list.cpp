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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) 
            return head;
        
        // Step 1: Find the length and the tail
        ListNode* tail = head;
        int n = 1;
        while (tail->next) {
            tail = tail->next;
            n++;
        }
        
        // Step 2: Reduce k (rotating by n is a full circle)
        k %= n;
        if (k == 0) 
            return head;
        
        // Step 3: Connect tail to head → circular list
        tail->next = head;
        
        // Step 4: Find the new tail: (n - k - 1) steps from head
        // The new head will be at position (n - k)
        ListNode* newTail = head;
        for (int i = 0; i < n - k - 1; i++) {
            newTail = newTail->next;
        }
        
        // Step 5: Break the circle
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        
        return newHead;
    }
};