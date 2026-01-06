//410. Split Array Largest Sum 
//https://leetcode.com/problems/split-array-largest-sum/description/

//brute force : O(Nlog(Sum))





class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int maxSum) {
        int currentSum = 0;
        int subarrays = 1;

        for (int num : nums) {
            if (currentSum + num <= maxSum) {
                currentSum += num;
            } else {
                subarrays++;
                currentSum = num;
                if (subarrays > k) return false;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = 0;
        int high = 0;

        for (int num : nums) {
            low = max(low, num);
            high += num;
        }

        int result = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canSplit(nums, k, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }
};