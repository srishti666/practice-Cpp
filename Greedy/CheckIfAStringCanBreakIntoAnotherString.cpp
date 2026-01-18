//1433. Check If a String Can Break Another String
//https://leetcode.com/problems/check-if-a-string-can-break-another-string/description/


// Sorting s1 = O(n \log n)
// Sorting s2 = O(n \log n) total = O(2n \log n)
//O(logn)

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        int n = s1.size();
        int countS1 =0;
        int countS2 = 0;

        for(int i=0; i<n; i++){
            if(s1[i] >= s2[i]){
                countS1++;
            }
            if(s2[i] >= s1[i]){
                countS2++;
            }
        }
        if(countS1 == n || countS2 == n) return true;
        return false;
    }
};
