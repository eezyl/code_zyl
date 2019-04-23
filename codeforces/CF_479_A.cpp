//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/479/A
//   Date    :   2019/04/23 (upload date)
//
//********************************************************

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int ans = -1;
    ans = max(ans, (a+b)*c);
    ans = max(ans, a*(b+c));
    ans = max(ans, a+b+c);
    ans = max(ans, a*b*c);
    ans = max(ans, a+b*c);
    ans = max(ans, a*b+c);
    printf("%d\n", ans);
    return 0;
}
