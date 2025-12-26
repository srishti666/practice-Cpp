//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
//378. Kth Smallest Element in a Sorted Matrix
//O(nm log(k))

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();

        priority_queue<int>pq;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                pq.push(matrix[i][j]);

                if(pq.size() > k)
                    pq.pop();
            }
        }
        return pq.top();
    }
};

//another solution

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
    
                   int n = matrix.size();
    
					int low = matrix[0][0]; // first element
					int high = matrix[n-1][n-1]; // Last element

					int mid, temp, count;

					while(low < high){
						mid = low + (high-low)/2;
						temp = n - 1;
						count = 0;

						// For each row count the elements that are smaller than mid
						for(int i = 0; i < n; i++){

							while(temp >= 0 && matrix[i][temp] > mid){
								temp--;
							}
							count+= (temp+1);
						}

						if(count < k)
							low = mid + 1;
						else
							high = mid;
						
					}
					return low;

		}
	};