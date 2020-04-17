//********************************************************//
//                                                        //
//   File    :   DisjointSet.h                            //
//   Author  :   eezyl                                    //
//   Synopsis:   data structure: Disjoint Set             //
//   Date    :   2020/04/17                               //
//                                                        //
//********************************************************//

#ifndef DISJOINTSET_H
#define DISJOINTSET_H
#include <vector>
#include <numeric> // std::iota

using std::vector;

class DisjointSet{
public:
    DisjointSet(int size) 
        : _size(size), _disjoint_size(size) 
    {
        _rank.resize(_size, 1);
        _parent.resize(_size);
        // =====================================================
        // initialization: _parent[i] = i
        // =====================================================
        std::iota(_parent.begin(), _parent.end(), 0);
    }
    
    bool isSameSet(int x, int y) { return ( find(x) == find(y) ); }
    int getSize() { return _size; }
    int getDisjointSize() { return _disjoint_size; }
    
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


#endif
