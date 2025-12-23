//https://leetcode.com/problems/single-element-in-a-sorted-array/description/?envType=problem-list-v2&envId=vpt5do15
//540. Single Element in a Sorted Array
//O(log n)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        if (high == 0) return nums[0];

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (mid % 2 == 1) {
                mid--;
            }

            if (nums[mid] == nums[mid + 1]) {
                low = mid + 2;
            } else {
                high = mid;
            }
        }
        return nums[low];
    }
};