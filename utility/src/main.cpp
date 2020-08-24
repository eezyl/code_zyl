// =====================================================
//   File    :   main.cpp                                 
//   Author  :   eezyl                                    
//   Synopsis:   Test for my function                     
//   Date    :   2020/04/13                             
// =====================================================


#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;


// =====================================================
#include "BIT.h"

int main()
{
    vector<int> aaa = {0, 1, 3, 4, 8, 6, 1, 4, 2};
    BIT<int> b(aaa);
    cout << b.query(1, 7) << endl;
    b.update(4, -1);
    cout << b.query(2, 5) << endl;
    return 0;
}
