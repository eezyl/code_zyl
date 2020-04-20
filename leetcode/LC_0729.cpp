// =====================================================
//   Author  :   eezyl
//   Synopsis:   leetcode template
//   Address :   https://leetcode.com/problems/my-calendar-i/ 
//   Date    :   2020/04/20
// =====================================================



class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        pair<int, int> p(start, end);
        for (auto &it: v) {
            if (isIntersect(it, p))
                return false;
        }
        v.push_back(p);

        return true;
    }
    bool isIntersect(pair<int, int>& a, pair<int, int>& b) {
        if (a.second <= b.first)
            return false;
        if (b.second <= a.first)
            return false;
        return true;
    }
    vector<pair<int, int> > v;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
