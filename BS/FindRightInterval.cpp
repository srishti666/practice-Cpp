//436. Find Right Interval
// https://leetcode.com/problems/find-right-interval/description/

// brute force
//TC  : O(n^2)
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> ans(n);

        for(int i=0; i<n ; i++){
            int index = -1;
            int minStart = INT_MAX;
            for(int j = 0; j<n; j++){
                if(intervals[j][0] >= intervals[i][1] && minStart > intervals[j][0]){
                    index = j;
                    minStart = intervals[j][0];
                }
            }
            ans[i] = index;
        }
        return ans;
    }
};
