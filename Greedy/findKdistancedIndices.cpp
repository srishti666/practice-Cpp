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