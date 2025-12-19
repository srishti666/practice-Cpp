//1351. Count Negative Numbers in a Sorted Matrix
//https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/
//O(m + n)


class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int r =m-1 , c = 0, count = 0;

        while(r>=0 && c<n){
            if(grid[r][c] < 0){
                r--;
                count += n - c;
            }
            else c++;
        }
        return count;
    }
};