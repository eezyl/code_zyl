// =====================================================
//   Author  :   eezyl
//   Synopsis:   leetcode template
//   Address :   https://leetcode.com/problems/my-calendar-ii/
//   Date    :   2020/04/20
// =====================================================



class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        pair<int, int> p(start, end);
        vector<pair<int, int> > v2;
        for (auto &a:v) {
            if (isIntersect(a, p)) {
                int le = max(a.first, p.first);
                int ri = min(a.second, p.second);
                pair<int, int> p2(le, ri);
                for (auto &b: v2) {
                    if (isIntersect(b, p2))
                        return false;
                }
                v2.push_back(p2);
            }
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
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
