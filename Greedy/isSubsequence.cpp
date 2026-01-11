//392. Is Subsequence
//https://leetcode.com/problems/is-subsequence/description/


//TC: O(n)
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int Slen = s.size();
        int Tlen = t.size();

        int i=0, j=0;

        while(i<Slen && j<Tlen){
            if(s[i] == t[j]){
                i++;
            }
            j++;
        }
        if(i == Slen)
        return true;
        else return false;
    }
};