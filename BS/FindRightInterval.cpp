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


//optimized : O(nlogn)


class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> mp;
        int n = intervals.size();
        
        for (int i = 0; i < n; i++) {
            mp[intervals[i][0]] = i;
        }

        vector<int> res;
        res.reserve(n);

        for (const auto& interval : intervals) {
            auto itr = mp.lower_bound(interval[1]);
            
            if (itr == mp.end()) {
                res.push_back(-1);
            } else {
                res.push_back(itr->second);
            }
        }
        
        return res;
    }
};

//another sol

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> mp;
        
        for (int i = 0; i < intervals.size(); i++) {
            mp[intervals[i][0]] = i; 
        }

        vector<int> res;
        for (auto& interval : intervals) {
            auto itr = mp.lower_bound(interval[1]);
            
            if (itr == mp.end()) {
                res.push_back(-1);
            } else {
                res.push_back(itr->second);
            }
        }
        return res;
    }
};



class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> mp;

        for(int i=0; i<intervals.size(); i++){
            mp[intervals[i][0]] = i;
        }

        vector<int> result;
        for(auto& interval : intervals){
            auto itr = mp.lower_bound(interval[1]);

            if(itr == )
        }
    }
}
