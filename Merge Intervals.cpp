/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool comp(Interval i1, Interval i2) {
    return i1.start <= i2.start;
}

class Solution {
public:
	/* sol_1: delete version (TLE)*/
    vector<Interval> merge(vector<Interval> &intervals) {
        // special
        if(intervals.size()<=1) return intervals;
        
        // sort by 1st element
        sort(intervals.begin(), intervals.end(), comp);
        
        // merge from the second element
        for(int i=1;i<intervals.size();) {
            if(intervals[i].start <= intervals[i-1].end){
                // merge + delete
                intervals[i-1].end = max(intervals[i-1].end, intervals[i].end);
                intervals.erase(intervals.begin()+i);
            }else{
                // next one
                i++;
            }
        }
        
        // return
        return intervals;
    }

	/* sol_2: start from a new vector */
    vector<Interval> merge_2(vector<Interval> &intervals) {
        // special
        if(intervals.size()<=1) return intervals;
        
        // sort
        sort(intervals.begin(), intervals.end(), comp);
        
        // merge
        vector<Interval> ret {intervals[0]};
        for(int i=1;i<intervals.size();i++){
            if(intervals[i].start <= ret[ret.size()-1].end){
                ret[ret.size()-1].end = max(ret[ret.size()-1].end, intervals[i].end);
            }else{
                ret.push_back(intervals[i]);
            }
        }
        
        // return
        return ret;
    }
};