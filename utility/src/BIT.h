//********************************************************//
//                                                        //
//   File    :   BIT.h                                    //
//   Author  :   eezyl                                    //
//   Synopsis:   template of Binary Indexed _tree          //
//   Date    :   2019/08/24                               //
//                                                        //
//********************************************************//

/* 
usage of BIT
int main()
{
    vector<int> aaa = {0, 1, 4, 4, 16, 6, 7, 4, 29};
    BIT<int> b(aaa);
    cout << b.query(2, 5) << endl;
    b.update(4, -1);
    cout << b.query(2, 5) << endl;
    return 0;
}
*/

#ifndef BIT_H
#define BIT_H

#include <vector>
#include <cfloat>

using std::vector;

// =====================================================
// The beginning index is 1
// =====================================================
template <class T>
class BIT {
public:
    BIT(vector<T>& in) 
    {
        _n = in.size();
        _in = in;
        _tree.resize(_n, 0);
        for (int i = 1; i < _n; ++i) {
            add(i, in[i]);
        }
    }
    
    void update(int i, T val) 
    {
        T diff = val - _in[i];
        add(i, diff);
        _in[i] = val;
    }
    
    // =====================================================
    // return sum(i, j) = sum(1, j) - sum(1, i-1)
    // =====================================================

    T query(int i, int j) 
    {
        return sum(j) - sum(i-1);
    }
    
    // =====================================================
    // The following function increases the array value at position k by x 
    // (x can be positive or negative):
    // =====================================================
    void add(int k, T x)
    {
        while (k <= _n) {
            _tree[k] += x;
            k += k&-k;
        }
    }

private:
    vector<T> _in;
    vector<T> _tree;
    int _n;
    
    // =====================================================
    // return sum(1, k)
    // =====================================================
    T sum(int k)
    {
        T a = 0;
        while (k >= 1) {
            a += _tree[k];
            k -= k&-k;
        }
        return a;
    }
};


#endif
