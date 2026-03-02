//141. Linked List Cycle
//https://leetcode.com/problems/linked-list-cycle/
//TC: O(n). SC: O(n)
//brute force

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


//Optimal 


//TC : O(n)  SC: O(1)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) return true;
        }
        return false;
    }
};
