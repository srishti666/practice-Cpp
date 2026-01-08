//410. Split Array Largest Sum / Book allocation
//https://leetcode.com/problems/split-array-largest-sum/description/

//brute force : O(Nlog(Sum))

// binary search

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

//optimized solution with right variables

class Solution {
    int countPartitions(vector<int>& nums, int maxSumLimit){
        long long currentSubarraySum = 0;
        int partitions = 1;

        for(int i=0; i<nums.size(); i++){
            if(currentSubarraySum + nums[i] <= maxSumLimit){
                currentSubarraySum += nums[i];
            }
            else{
                partitions++;
                currentSubarraySum = nums[i];
            }
        }
        return partitions;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low <= high){
            int mid = low+(high - low)/2;

            int partitions = countPartitions(nums, mid);

            if(partitions > k){
                low = mid + 1;
            } 
            else high = mid - 1 ;
        }
        return low;
    }
};


//striver solution : https://www.youtube.com/watch?v=thUd_WJn6wk

//O(log(sum-max)*n)

// book allocation
class Solution {
public:
    int countStudents(vector<int>& nums, int pages){
        int students = 1;
        long long pagesStudents = 0;
        for(int i = 0; i<nums.size(); i++){
            if(pagesStudents + nums[i] <= pages){
                pagesStudents += nums[i];
            }
            else {
                students++;
                pagesStudents = nums[i];
            }
        }
        return students;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(),0);

        while(low <= high){
            int mid = low + (high-low)/2;
            int students = countStudents(nums, mid);

            if(students > k){
                low = mid + 1;
            } 
            else high = mid - 1;
        }
        return low;
    }
};