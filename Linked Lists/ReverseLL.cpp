//206. Reverse Linked List

//https://leetcode.com/problems/reverse-linked-list/description/

//TC : O(n) SC : O(n)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
         stack<int> st;

        // Temporary pointer to traverse the list
        ListNode* temp = head;

        // Traverse and push all node values to stack
        while (temp != NULL) {
            st.push(temp->val);
            temp = temp->next;
        }

        // Reset temp back to head
        temp = head;

        // Reassign values from stack in reverse order
        while (temp != NULL) {
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }

        // Return the modified head
        return head;
    }
};