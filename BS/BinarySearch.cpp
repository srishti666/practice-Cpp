//https://leetcode.com/problems/binary-search/?envType=problem-list-v2&envId=vpt5do15
//704. Binary Search

#include <vector>
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int h = nums.size()-1;
        int l = 0;
        
        while(l<=h){
            int mid = (h+l)/2;
            if(target == nums[mid]) return mid;

            else if(target > nums[mid])
                l = mid+1;
            
            else h = mid-1;
        }
        return -1;
    }
};