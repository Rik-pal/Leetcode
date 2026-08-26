class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Min heap
        priority_queue<
            ListNode*,
            vector<ListNode*>,
            compare
        > pq;

        // Put first node of every list into heap
        for (ListNode* list : lists) {
            if (list != nullptr) {
                pq.push(list);
            }
        }

        // Dummy node
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (!pq.empty()) {

            // Get smallest node
            ListNode* smallest = pq.top();
            pq.pop();

            // Add it to result
            tail->next = smallest;
            tail = tail->next;

            // Add next node from the same list
            if (smallest->next != nullptr) {
                pq.push(smallest->next);
            }
        }

        return dummy->next;
    }

private:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
};