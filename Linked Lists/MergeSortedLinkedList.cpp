//https://leetcode.com/problems/merge-two-sorted-lists/
//21. Merge Two Sorted Lists
// Brute Force

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> nodes;
        
        while (list1 != NULL) {
            nodes.push_back(list1->val);
            list1 = list1->next;
        }
        
        while (list2 != NULL) {
            nodes.push_back(list2->val);
            list2 = list2->next;
        }
        
        if (nodes.empty()) return NULL;
        
        sort(nodes.begin(), nodes.end());
        
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        
        for (int i = 0; i < nodes.size(); i++) {
            temp->next = new ListNode(nodes[i]);
            temp = temp->next;
        }
        
        ListNode* result = dummy->next;
        delete dummy; 
        return result;
    }
};