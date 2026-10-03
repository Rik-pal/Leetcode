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
    ListNode* partition(ListNode* head, int x) {
        ListNode lessDummy, geDummy;        // two anchor points
        ListNode* lessTail = &lessDummy;
        ListNode* geTail   = &geDummy;

        for (ListNode* curr = head; curr; curr = curr->next) {
            if (curr->val < x) {
                lessTail->next = curr;
                lessTail = curr;
            } else {
                geTail->next = curr;
                geTail = curr;
            }
        }

        lessTail->next = geDummy.next;      // stitch the two lists
        geTail->next = nullptr;             // terminate (avoid cycle!)

        return lessDummy.next;
    }
};