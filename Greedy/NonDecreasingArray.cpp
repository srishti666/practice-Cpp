//665. Non-decreasing Array
//https://leetcode.com/problems/non-decreasing-array/description/

//TC: O(n) SC: O(1)

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                count++;
                
                if (count > 1) return false;

                if (i == 0 || nums[i - 1] <= nums[i + 1]) {
                    nums[i] = nums[i + 1];
                } 
                else {
                    nums[i + 1] = nums[i];
                }
            }
        }

        return true;
    }
};