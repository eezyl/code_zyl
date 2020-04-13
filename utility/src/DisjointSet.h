//********************************************************//
//                                                        //
//   File    :   DisjointSet.h                            //
//   Author  :   eezyl                                    //
//   Synopsis:   data structure: Disjoint Set             //
//   Date    :   2020/04/13                               //
//                                                        //
//********************************************************//

#ifndef DISJOINTSET_H
#define DISJOINTSET_H
#include <vector>
#include <numeric> // std::iota

using std::vector;

class DisjointSet{
public:
    DisjointSet(int size) :_size(size) {
        _rank.resize(_size, 1);
        _parent.resize(_size);
        std::iota(_parent.begin(), _parent.end(), 0);
    }
    
    bool isSameSet(int x, int y) {
        return ( find(x) == find(y) );
    }
    
    int find(int x) {
        if (_parent[x] != x)
            _parent[x] = find(_parent[x]);
        return _parent[x];
    }
    
    void unionElement(int x, int y) {
        int xset = find(x);
        int yset = find(y);
        
        if (xset == yset)
            return;
        
        if (_rank[xset] < _rank[yset])
            _parent[xset] = yset;
        else if (_rank[xset] > _rank[yset])
            _parent[yset] = xset;
        else {
            _parent[yset] = xset;
            ++_rank[xset];
        }
    }
private:
    int _size;
    vector<int> _rank;
    vector<int> _parent;
};


#endif