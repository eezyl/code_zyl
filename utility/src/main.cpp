//********************************************************//
//                                                        //
//   File    :   main.cpp                                 //
//   Author  :   eezyl                                    //
//   Synopsis:   Test for my function                     //
//   Date    :   2019/04/14                               //
//                                                        //
//********************************************************//


#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;


// =====================================================
#include "SegTree.h"

int main()
{
    vector<double> aaa;
    aaa.push_back(0.2);
    aaa.push_back(0.5);
    aaa.push_back(123);
    MaxSegTree<double> qq(aaa);
    cout << qq.query(0, 2) << endl; // 123.7
    qq.update(2, 0);
    cout << qq.query(0, 2) << endl; // 126.5
    
    
    return 0;
}
