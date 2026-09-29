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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr) {
            // Detect a duplicate run
            if (curr->next && curr->val == curr->next->val) {
                int dupVal = curr->val;
                // Skip ALL nodes with this value
                while (curr && curr->val == dupVal) {
                    curr = curr->next;
                }
                // Link past the entire run (no node from run survives)
                prev->next = curr;
            } else {
                // Distinct node — confirm it
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};