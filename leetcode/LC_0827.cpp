// =====================================================
//   Author  :   eezyl
//   Synopsis:   leetcode template
//   Address :   https://leetcode.com/problems/making-a-large-island/
//   Date    :   2020/04/20
// =====================================================


class DisjointSet{
public:
    DisjointSet(int size) 
        : _size(size), _disjoint_size(size) 
    {
        _rank.resize(_size, 1);
        _parent.resize(_size);
        // =====================================================
        // initialization: parent[i] = i
        // =====================================================
        std::iota(_parent.begin(), _parent.end(), 0);
    }
    
    bool isSameSet(int x, int y) { return ( find(x) == find(y) ); }
    int size() { return _size; }
    int disjointSize() { return _disjoint_size; }
    
    // =====================================================
    // find the parent of x with path compression technique
    // =====================================================
    int find(int x) 
    {
        if (_parent[x] != x)
            _parent[x] = find(_parent[x]);
        return _parent[x];
    }
    
    // =====================================================
    // union two elements with balanced tree technique
    // =====================================================
    void unionElement(int x, int y) 
    {
        int xset = find(x);
        int yset = find(y);
        
        if (xset == yset)
            return;
        
        if (_rank[xset] < _rank[yset])
            _parent[xset] = yset;
        else {
            if (_rank[xset] == _rank[yset])
                ++_rank[xset];
            _parent[yset] = xset;
        }
        --_disjoint_size;
    }
private:
    int _size;
    int _disjoint_size;
    vector<int> _rank;
    vector<int> _parent;
};


class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int id = i*n+j;
                    if (i+1 < n && grid[i+1][j] == 1)
                        ds.unionElement(id, id+n);
                    if (j+1 < n && grid[i][j+1] == 1)
                        ds.unionElement(id, id+1);
                }
            }
        }
        vector<int> v(n*n, 0);
        int ans = 0;
        for (int i = 0; i < ds.size(); ++i) {
            int id = ds.find(i);
            ++v[id];
            ans = max(ans, v[id]);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    int id = i*n+j;
                    set<int> s;
                    if (i-1 >= 0 && grid[i-1][j] == 1)
                        s.insert(ds.find(id-n));
                    if (i+1 < n && grid[i+1][j] == 1)
                        s.insert(ds.find(id+n));
                    if (j-1 >= 0 && grid[i][j-1] == 1)
                        s.insert(ds.find(id-1));
                    if (j+1 < n && grid[i][j+1] == 1)
                        s.insert(ds.find(id+1));
                    int sum = 1;
                    for (auto c: s)
                        sum += v[c];
                    ans = max(ans, sum);
                }
            }
        }
        
        return ans;
    }
};
