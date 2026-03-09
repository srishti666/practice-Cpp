// 23. Merge k Sorted Lists
//https://leetcode.com/problems/merge-k-sorted-lists/


class Solution {
public:

    ListNode* mergeTwoSortedLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        if(l1->val <= l2->val){
            l1->next = mergeTwoSortedLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoSortedLists(l2->next, l1);
            return l2;
        }
        return NULL;
    }

    ListNode* PartitionAndMerge(int start, int end,vector<ListNode*>& lists){
        if(start > end) return NULL;
        if(start == end) return lists[start];

        int mid = start + (end-start)/2;

        ListNode* L1 = PartitionAndMerge(start, mid, lists);
        ListNode* L2 = PartitionAndMerge(mid+1, end, lists);

        return mergeTwoSortedLists(L1, L2);
        
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        if(n == 0) return NULL;
        return PartitionAndMerge(0, n-1, lists);
    }
};