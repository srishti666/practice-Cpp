//2200. Find All K-Distant Indices in an Array
//https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/description/

//Brute force
//TC : O(n*n)

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums.size(); j++){
                if(nums[j] == key && abs(i-j) <= k){
                    ans.push_back(i); 
                    break;  
                }
            }
        }
        return ans;
    }
};


//OPTIMIZED

//tc: O(n)

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int n = nums.size();
        int last_added = -1;

        for (int j = 0; j < n; j++) {
            if (nums[j] == key) {
                int start = max(last_added + 1, j - k);
                int end = min(n - 1, j + k);

                for (int i = start; i <= end; i++) {
                    ans.push_back(i);
                    last_added = i;
                }
            }
        }
        
        return ans;
    }
};


//Approach (Simply iterate and find valid indices. Just be careful of corner cases and overlapping indices
//T.C : O(n), we visit every index only 2 times.
//S.C : O(1)
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();

        vector<int> result;

        for(int j = 0; j < n; j++) {
            if(nums[j] == key) {
                int start = max(j-k, 0);
                int end   = min(j+k, n-1);

                if(result.size() > 0 && result.back() >= start) {
                    start = result.back()+1;
                }

                for(int i = start; i <= end; i++) {
                    result.push_back(i);
                }
            }
        }
        return result;
    }
};