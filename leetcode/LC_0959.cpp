// =====================================================
//   Author  :   eezyl
//   Synopsis:   leetcode template
//   Address :   https://leetcode.com/problems/regions-cut-by-slashes/
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
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        DisjointSet ds(n*(n+1)*2);
        int base = 0;
        int step = n + n + 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int id = base+j;
                if (grid[i][j] == ' ') {
                    ds.unionElement(id, id+n);
                    ds.unionElement(id, id+n+1);
                    ds.unionElement(id, id+step);
                } else if (grid[i][j] == '/') {
                    ds.unionElement(id, id+n);
                    ds.unionElement(id+n+1, id+step);
                } else {
                    ds.unionElement(id, id+n+1);
                    ds.unionElement(id+n, id+step);
                }
            }
            base += step;
        }

        return ds.disjointSize();
        
    }
};
