/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
	/* sol_1: linear search for the proper position */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // special
        if(intervals.size()==0 || newInterval.start>intervals[intervals.size()-1].end){
            intervals.push_back(newInterval);
            return intervals;
        }
        if(newInterval.end < intervals[0].start){
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        
        // find the merge
        vector<Interval> ret;
        for(int i=0;i<intervals.size();i++){
            Interval curr = intervals[i];
            if(!(newInterval.end < curr.start || newInterval.start > curr.end)) {
                curr.start = min(intervals[i].start, newInterval.start);
                curr.end = max(intervals[i].end, newInterval.end);
                ret.push_back(curr);
                for(int j=i+1;j<intervals.size();j++) {
                    if(intervals[j].start <= ret[ret.size()-1].end){
                        ret[ret.size()-1].end = max(ret[ret.size()-1].end, intervals[j].end);
                    }else{
                        ret.push_back(intervals[j]);
                    }
                }
                return ret;
            } else if(newInterval.end < intervals[i+1].start){
                ret.push_back(curr);
                ret.push_back(newInterval);
                for(int j=i+1;j<intervals.size();j++) ret.push_back(intervals[j]);
                return ret;
            } else {
                ret.push_back(curr);
            }
        }
    }

	/* sol_2: binary search for the proper solution */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // if zero member
        if(intervals.size()==0){
            intervals.push_back(newInterval);
            return intervals;
        }
        
        // if one member
        if(intervals.size()==1){
            if(newInterval.end < intervals[0].start){
                intervals.insert(intervals.begin(), newInterval);
                return intervals;
            }
            if(newInterval.start > intervals[0].end){
                intervals.push_back(newInterval);
                return intervals;
            }
            intervals[0].start = min(intervals[0].start, newInterval.start);
            intervals[0].end = max(intervals[0].end, newInterval.end);
            return intervals;
        }
        
        // binary search
        int l=0, r=intervals.size()-1;
        int m;
        while(l+1 < r){
            m=(l+r)/2;
            if(newInterval.start > intervals[m-1].end){
                l=m;
            }else {
                r=m;
            }
        }
        if(newInterval.start <= intervals[l].end){
            m=l;
        }else if(newInterval.start <= intervals[r].end){
            m=r;
        }else{
            m=r+1;
        }
        
        // merge
        vector<Interval>ret;
        for(int i=0;i<m;i++) ret.push_back(intervals[i]);
        ret.push_back(newInterval);
        for(int i=m;i<intervals.size();i++){
            if(intervals[i].start<=ret[ret.size()-1].end){
                ret[ret.size()-1].start=min(ret[ret.size()-1].start, intervals[i].start);
                ret[ret.size()-1].end=max(ret[ret.size()-1].end, intervals[i].end);
            }else{
                ret.push_back(intervals[i]);
            }
        }
        
        // return
        return ret;
    }
};