//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/4/A
//   Date    :   2019/04/23 (upload date)
//
//********************************************************

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
    int w;
    scanf("%d", &w);
    if (w%2 == 1 || w == 2)
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
}
