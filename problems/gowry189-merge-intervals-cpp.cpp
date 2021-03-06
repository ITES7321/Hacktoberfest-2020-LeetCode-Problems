/**
 * Solution to <merge-intervals> at LeetCode in <c++>
 *
 * author: <gowry189>
 * ref: <https://leetcode.com/problems/merge-intervals/>
 */
 
 class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        if(intervals.size() == 0){
            return mergedIntervals;
        }
        sort(intervals.begin(),intervals.end());
        vector<int>tempInterval = intervals[0];
        for(auto it: intervals){
            if(tempInterval[1] >= it[0]){
                tempInterval[1] = max(it[1],tempInterval[1]);
            }
            else{
                mergedIntervals.push_back(tempInterval);
                tempInterval = it;
            }
        }
        mergedIntervals.push_back(tempInterval);
        return mergedIntervals;
    }
};
