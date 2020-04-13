//********************************************************//
//                                                        //
//   File    :   SegTree.h                                //
//   Author  :   eezyl                                    //
//   Synopsis:   template of SegTree: sum, max, min       //
//   Date    :   2019/04/13                               //
//                                                        //
//********************************************************//

/* 
usage of SumSegTree
int main()
{
    vector<double> aaa;
    aaa.push_back(0.2);
    aaa.push_back(0.5);
    aaa.push_back(123);
    SumSegTree<double> qq(aaa);
    cout << qq.query(0, 2) << endl; // 123.7
    qq.update(0, 3);
    cout << qq.query(0, 2) << endl; // 126.5
    return 0;
}
*/

#ifndef SEGTREE_H
#define SEGTREE_H

#include <vector>
#include <cfloat>

using std::vector;

// =====================================================
// left close, right open  [0, size)
// =====================================================
template <class T>
class SumSegTree {
public:
    SumSegTree(const vector<T>& input_nums)
        : _dup_nums(input_nums)
    {
        _glob_size = _dup_nums.size();
        
        // =====================================================
        // find the least power of 2 that larger than size
        // =====================================================
        unsigned s = 1;
        for (; s < _dup_nums.size(); s <<= 1)
            ;
        s <<= 1;

        _seg_tree.resize(s);
        if (_dup_nums.size() != 0)
            constructSegTree(0, _glob_size, 1);
    }

    void update(int i, T val)
    {
        _idx = i;
        _n = val;
        update(0, _glob_size, 1);
    }
    
    // =====================================================
    // the query is [i, j] -> convert to [i ,j+1)
    // =====================================================
    T query(int i, int j)
    {
        _x1 = i;
        _x2 = j+1;
        _total = 0;
        query(0, _glob_size, 1);
        return _total;
    }

private:
    unsigned _glob_size;
    vector<T> _seg_tree;
    const vector<T> &_dup_nums;
    
    // use for update
    int _idx;
    T _n;
    
    // use for query
    int _x1, _x2;
    T _total;
    
    void constructSegTree(int L, int R, int i)
    {
        if (L == R-1) {
            _seg_tree[i] = _dup_nums[L];
            return;
        }

        int M = getMid(L, R);
        constructSegTree(L, M, LC(i));
        constructSegTree(M, R, RC(i));
        _seg_tree[i] = getTotal(_seg_tree[LC(i)], _seg_tree[RC(i)]);
    }

    void update(int L, int R, int i)
    {
        if (L == R-1) {
            _seg_tree[i] = _n;
            return;
        }

        int M = getMid(L, R);
        if (_idx < M)
            update(L, M, LC(i));
        if (_idx >= M)
            update(M, R, RC(i));
        _seg_tree[i] = getTotal(_seg_tree[LC(i)], _seg_tree[RC(i)]);
    }

    void query(int L, int R, int i)
    {
        if (_x1 <= L && R <= _x2) {
            _total = getTotal(_total, _seg_tree[i]);
            return;
        }

        int M = getMid(L, R);
        if (_x1 < M)
            query(L, M, LC(i));
        if (_x2 > M)
            query(M, R, RC(i));
    }
    
    // left child(LC) and right child(RC)
    inline int LC(int i)  { return 2*i; }
    inline int RC(int i)  { return 2*i+1; }
    inline int getMid(int l, int r) { return l + (r-l)/2; }
    inline T getTotal(T a, T b) { return a + b; }
};



// =====================================================
// left close, right open  [0, size)
// =====================================================
template <class T>
class MaxSegTree {
public:
    MaxSegTree(const vector<T>& input_nums)
        : _dup_nums(input_nums)
    {
        _glob_size = _dup_nums.size();
        
        // =====================================================
        // find the least power of 2 that larger than size
        // =====================================================
        unsigned s = 1;
        for (; s < _dup_nums.size(); s <<= 1)
            ;
        s <<= 1;

        _seg_tree.resize(s);
        if (_dup_nums.size() != 0)
            constructSegTree(0, _glob_size, 1);
    }

    void update(int i, T val)
    {
        _idx = i;
        _n = val;
        update(0, _glob_size, 1);
    }
    
    // =====================================================
    // the query is [i, j] -> convert to [i ,j+1)
    // =====================================================
    T query(int i, int j)
    {
        _x1 = i;
        _x2 = j+1;
        _min_val = -2147483647;
        query(0, _glob_size, 1);
        return _min_val;
    }

private:
    unsigned _glob_size;
    vector<T> _seg_tree;
    const vector<T> &_dup_nums;
    
    // use for update
    int _idx;
    T _n;
    
    // use for query
    int _x1, _x2;
    T _min_val;
    
    void constructSegTree(int L, int R, int i)
    {
        if (L == R-1) {
            _seg_tree[i] = _dup_nums[L];
            return;
        }

        int M = getMid(L, R);
        constructSegTree(L, M, LC(i));
        constructSegTree(M, R, RC(i));
        _seg_tree[i] = getMax(_seg_tree[LC(i)], _seg_tree[RC(i)]);
    }

    void update(int L, int R, int i)
    {
        if (L == R-1) {
            _seg_tree[i] = _n;
            return;
        }

        int M = getMid(L, R);
        if (_idx < M)
            update(L, M, LC(i));
        if (_idx >= M)
            update(M, R, RC(i));
        _seg_tree[i] = getMax(_seg_tree[LC(i)], _seg_tree[RC(i)]);
    }

    void query(int L, int R, int i)
    {
        if (_x1 <= L && R <= _x2) {
            _min_val = getMax(_min_val, _seg_tree[i]);
            return;
        }

        int M = getMid(L, R);
        if (_x1 < M)
            query(L, M, LC(i));
        if (_x2 > M)
            query(M, R, RC(i));
    }
    
    // left child(LC) and right child(RC)
    inline int LC(int i)  { return 2*i; }
    inline int RC(int i)  { return 2*i+1; }
    inline int getMid(int l, int r) { return l + (r-l)/2; }
    inline T getMax(T a, T b) { return (a < b) ? b : a; }
};

// =====================================================
// left close, right open  [0, size)
// =====================================================
template <class T>
class MinSegTree {
public:
    MinSegTree(const vector<T>& input_nums)
        : _dup_nums(input_nums)
    {
        _glob_size = _dup_nums.size();
        
        // =====================================================
        // find the least power of 2 that larger than size
        // =====================================================
        unsigned s = 1;
        for (; s < _dup_nums.size(); s <<= 1)
            ;
        s <<= 1;

        _seg_tree.resize(s);
        if (_dup_nums.size() != 0)
            constructSegTree(0, _glob_size, 1);
    }

    void update(int i, T val)
    {
        _idx = i;
        _n = val;
        update(0, _glob_size, 1);
    }
    
    // =====================================================
    // the query is [i, j] -> convert to [i ,j+1)
    // =====================================================
    T query(int i, int j)
    {
        _x1 = i;
        _x2 = j+1;
        _max_val = 2147483647;
        query(0, _glob_size, 1);
        return _max_val;
    }

private:
    unsigned _glob_size;
    vector<T> _seg_tree;
    const vector<T> &_dup_nums;
    
    // use for update
    int _idx;
    T _n;
    
    // use for query
    int _x1, _x2;
    T _max_val;
    
    void constructSegTree(int L, int R, int i)
    {
        if (L == R-1) {
            _seg_tree[i] = _dup_nums[L];
            return;
        }

        int M = getMid(L, R);
        constructSegTree(L, M, LC(i));
        constructSegTree(M, R, RC(i));
        _seg_tree[i] = getMin(_seg_tree[LC(i)], _seg_tree[RC(i)]);
    }

    void update(int L, int R, int i)
    {
        if (L == R-1) {
            _seg_tree[i] = _n;
            return;
        }

        int M = getMid(L, R);
        if (_idx < M)
            update(L, M, LC(i));
        if (_idx >= M)
            update(M, R, RC(i));
        _seg_tree[i] = getMin(_seg_tree[LC(i)], _seg_tree[RC(i)]);
    }

    void query(int L, int R, int i)
    {
        if (_x1 <= L && R <= _x2) {
            _max_val = getMin(_max_val, _seg_tree[i]);
            return;
        }

        int M = getMid(L, R);
        if (_x1 < M)
            query(L, M, LC(i));
        if (_x2 > M)
            query(M, R, RC(i));
    }
    
    // left child(LC) and right child(RC)
    inline int LC(int i)  { return 2*i; }
    inline int RC(int i)  { return 2*i+1; }
    inline int getMid(int l, int r) { return l + (r-l)/2; }
    inline T getMin(T a, T b) { return (a < b) ? a : b; }
};


template <class T>
class SegTree {
public:
    SegTree(const vector<T>& input_nums)
        : max_seg_tree(input_nums), min_seg_tree(input_nums), sum_seg_tree(input_nums)
    {}
    
    void update(int i, T val)
    {
        max_seg_tree.update(i, val);
        min_seg_tree.update(i, val);
        sum_seg_tree.update(i, val);
    }
    
    T query_max(int i, int j) { return max_seg_tree.query(i, j); }
    T query_min(int i, int j) { return min_seg_tree.query(i, j); }
    T query_sum(int i, int j) { return sum_seg_tree.query(i, j); }
    
private:
    MaxSegTree<T> max_seg_tree;
    MinSegTree<T> min_seg_tree;
    SumSegTree<T> sum_seg_tree;
};


#endif
