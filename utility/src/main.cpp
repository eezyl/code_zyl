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
    long long x, y, g;
    cout << find_any_solution(14, 10000, -4, x ,y, g) << endl;
    cout << x << endl;
    cout << y << endl;
    cout << 14*x + 10000*y << endl;
    
    cout << g << endl;
    return 0;
}
