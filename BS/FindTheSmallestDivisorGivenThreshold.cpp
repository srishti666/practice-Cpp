//1283. Find the Smallest Divisor Given a Threshold
//https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/


class Solution {
    long long calculateSum(vector<int>& nums, int divisor) {
        long long totalSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            totalSum += (nums[i] + divisor - 1) / divisor;
        }
        return totalSum;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (calculateSum(nums, mid) > threshold) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};
