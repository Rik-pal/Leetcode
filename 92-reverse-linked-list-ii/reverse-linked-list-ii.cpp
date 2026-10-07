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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0, head);

        // 1. Move `prev` to the node just before position `left`
        ListNode* prev = dummy;
        for (int i = 1; i < left; ++i)
            prev = prev->next;

        // 2. Reverse the segment [left, right] by repeatedly moving
        //    the node after `curr` to right after `prev`
        ListNode* curr = prev->next;
        for (int i = 0; i < right - left; ++i) {
            ListNode* nextNode = curr->next;
            curr->next = nextNode->next;
            nextNode->next = prev->next;
            prev->next = nextNode;
        }

        return dummy->next;
    }
};