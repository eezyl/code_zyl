//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/486/A
//   Date    :   2019/04/23 (upload date)
//
//********************************************************

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long I64d;

int main()
{
    I64d n;
    scanf("%I64d", &n);
    if (n % 2 == 1)
        printf("%I64d\n", (n+1)/2 * -1);
    else
        printf("%I64d\n", n/2);
    return 0;
}
