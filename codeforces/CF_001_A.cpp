//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/1/A
//   Date    :   2019/04/23 (upload date)
//
//********************************************************

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

typedef long long ll;

int main()
{
    ll x, y, a;
    scanf("%I64d %I64d %I64d", &x, &y, &a);
    printf("%I64d\n", ((x+a-1)/a) * ((y+a-1)/a));

    return 0;
}
