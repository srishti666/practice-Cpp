//1029. Two City Scheduling
//https://leetcode.com/problems/two-city-scheduling/description/

//using sorting
//TC: O(nlogn)

class Solution {
    static bool comparator(const vector<int>& a, const vector<int>& b) {
        return (a[0] - a[1]) < (b[0] - b[1]);
    }

public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        sort(costs.begin(), costs.end(), comparator);
        
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            ans += (i < n / 2) ? costs[i][0] : costs[i][1];
        }
        
        return ans;
    }
};