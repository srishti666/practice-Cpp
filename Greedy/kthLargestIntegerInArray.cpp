//1985. Find the Kth Largest Integer in the Array
//https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/description/

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), [](const string& a, const string& b) {
            if (a.size() != b.size()) {
                return a.size() < b.size();
            }
            return a < b;
        });

        return nums[n - k];
    }
};