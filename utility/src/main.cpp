//********************************************************//
//                                                        //
//   File    :   main.cpp                                 //
//   Author  :   eezyl                                    //
//   Synopsis:   Test for my function                     //
//   Date    :   2020/04/13                               //
//                                                        //
//********************************************************//


#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;


// =====================================================
#include "DisjointSet.h"

int main()
{
    DisjointSet S(10);
    cout << S.isSameSet(1, 3) << endl;
    S.unionElement(1, 2);
    S.unionElement(2, 3);
    cout << S.isSameSet(1, 3) << endl;
    
    return 0;
}
