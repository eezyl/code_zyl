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
#include "Arithmetic.h"
using namespace std;


// =====================================================
#include "BIT.h"

int main()
{
    int x, y, g;
    cout << exgcd(14, 10000, 10000-6, x ,y, g) << endl;
    cout << x << endl;
    cout << y << endl;
    return 0;
}
