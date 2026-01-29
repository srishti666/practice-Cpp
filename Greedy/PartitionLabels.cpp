//763. Partition Labels
//https://leetcode.com/problems/partition-labels/description/

//tc

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastIdx(26, 0);
        for (int i = 0; i < s.length(); i++) {
            lastIdx[s[i] - 'a'] = i;
        }

        vector<int> result;
        int start = 0;
        int end = 0;

        for (int i = 0; i < s.length(); i++) {
            end = max(end, lastIdx[s[i] - 'a']);

            if (i == end) {
                result.push_back(i - start + 1);
                start = i + 1; 
            }
        }

        return result;
    }
};