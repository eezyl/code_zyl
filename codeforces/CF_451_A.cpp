//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/451/A
//   Date    :   2019/04/23 (upload date)
//
//********************************************************

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int ans = min(a, b);

    if (ans % 2 == 1)
        printf("Akshat\n");
    else
        printf("Malvika\n");

    return 0;
}
