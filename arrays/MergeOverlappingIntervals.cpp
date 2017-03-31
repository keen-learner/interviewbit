/*
Merge Overlapping Intervals
Given a collection of intervals, merge all overlapping intervals.

For example:

Given [1,3],[2,6],[8,10],[15,18],

return [1,6],[8,10],[15,18].

Make sure the returned intervals are sorted

LEETCODE: # 56 : https://leetcode.com/problems/merge-intervals/#/description

*/

vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<Interval> res;
    if (A.empty()) return res;
    sort(A.begin(), A.end(), [](Interval a, Interval b) {
        return a.start < b.start;
    });
    res.push_back(A[0]);
    for (int i = 1 ; i < A.size(); ++i ) {
        if (A[i]. start <= res.back().end) {
            res.back().end = max(res.back().end, A[i].end);
        }
        else {
            res.push_back(A[i]);
        }
    }
    return res;
}

/*
// official

class Solution {
    public:
        bool myCmp(Interval a, Interval b) {
            return a.start < b.start;
        }

        vector<Interval> merge(vector<Interval> &intervals) {
            if(intervals.size() < 2) {
                return intervals;
            }
            sort(intervals.begin(), intervals.end(), myCmp);
            int first = 0;
            for(int second = 1; second < intervals.size(); second++) {
                // There is overlap in intervals at first and second position.
                if(intervals[second].start <= intervals[first].end) {
                    // We merge the second interval into the first one and modify the first interval to reflect it. 
                    intervals[first].end = max(intervals[second].end, intervals[first].end);
                }
                else {
                    // No overlap between first and second. Move forward. 
                    ++first;
                    intervals[first].start = intervals[second].start;
                    intervals[first].end = intervals[second].end;
                }
            }
            intervals.erase(intervals.begin() + first + 1, intervals.end());
            return intervals;
        }
};

*/
