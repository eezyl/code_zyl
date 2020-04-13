//********************************************************//
//                                                        //
//   File    :   Sorting.h                                //
//   Author  :   eezyl                                    //
//   Synopsis:   Collection of the usage of sorting       //
//   Date    :   2019/04/18                               //
//                                                        //
//********************************************************//

#include <algorithm> // std::sort
#include <vector>
#include <cstdlib> // tie
#include <numeric> // iota

class StudentForSorting {
public:
    StudentForSorting(int h = -1, double w = -1)
        : pub_height(h), pub_weight(w), pri_height(h), pri_weight(w)
    {}
    int height() const { return pri_height; }
    double weight() const { return pri_weight; }
    
    // =====================================================
    // Methond 1
    // Define the public overloaded operator< 
    // The comparison variables can be private
    // Usage: std::sort(v.begin(), v.end());
    // =====================================================
    bool operator<(const StudentForSorting& a) const {
        //return std::tie(pri_height, pri_weight) < std::tie(a.pri_height, a.pri_weight);
        return (height() != a.height()) ?  (height() < a.height()) : (weight() < a.weight());
    }
    // =====================================================
    // Methond 2
    // Define the public static member compare function
    // The comparison variables can be private
    // Usage: std::sort(v.begin(), v.end(), StudentForSorting::decrease);
    // =====================================================
    bool static decrease(const StudentForSorting& a,  const StudentForSorting& b) {
        return std::tie(a.pri_height, a.pri_weight) < std::tie(b.pri_height, b.pri_weight);
    }
    
    int pub_height;
    double pub_weight;
    
private:
    int pri_height;
    double pri_weight;
};
/*
// =====================================================
// Methond 3
// Define the global compare function
// The comparison variables need to be public
// Usage: std::sort(v.begin(), v.end(), myfunctionForSorting);
// =====================================================
bool myfunctionForSorting (const StudentForSorting& a,  const StudentForSorting& b)
{
    return std::tie(a.height(), a.weight()) < std::tie(b.height(), b.weight());
    // return std::tie(a.pub_height, a.pub_weight) < std::tie(b.pub_height, b.pub_weight);
}
*/
/*
// =====================================================
// Methond 4
// Define the global operator<  !warning: conflict with member overloaded operator
// The comparison variables need to be public
// Usage: std::sort(v.begin(), v.end());
// =====================================================
bool operator<(const StudentForSorting& a,  const StudentForSorting& b)
{
    return std::tie(a.height(), a.weight()) < std::tie(b.height(), b.weight());
    // return std::tie(a.pub_height, a.pub_weight) < std::tie(b.pub_height, b.pub_weight);
}
*/

/*
// =====================================================
// Methond 5
Use lambda
The comparison variables need to be public
// =====================================================
sort(v.begin(), v.end(), [](const StudentForSorting& a,  const StudentForSorting& b) -> bool {
    return std::tie(a.height(), a.weight()) < std::tie(b.height(), b.weight());
    // return std::tie(a.pub_height, a.pub_weight) < std::tie(b.pub_height, b.pub_weight);
}
);
*/

// =====================================================
// Sorting and keeping track of indexes
// usage:
// for (auto i: sort_indexes(v)) {
// cout << v[i] << endl;
// }
// =====================================================
template <typename T>
std::vector<size_t> sort_indexes(const std::vector<T> &v) {
    
    // =====================================================
    // initialize original index locations
    // =====================================================
    std::vector<size_t> idx(v.size());
    std::iota(idx.begin(), idx.end(), 0);

    // =====================================================
    // sort indexes based on comparing values in v
    // =====================================================
    std::sort(idx.begin(), idx.end(),
            [&v](size_t i1, size_t i2) { return v[i1] < v[i2]; });
    return idx;
}


