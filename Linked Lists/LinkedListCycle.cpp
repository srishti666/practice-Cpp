//141. Linked List Cycle
//https://leetcode.com/problems/linked-list-cycle/
//TC: O(n). SC: O(n)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, bool> mpp;
        ListNode* temp = head;

        while (temp != NULL) {
            if (mpp.count(temp)) {
                return true;
            }
            mpp[temp] = true;     
            temp = temp->next;
        }
        return false;
    }
};
