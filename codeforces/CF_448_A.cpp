//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/448/A
//   Date    :   2019/04/17 (upload date)
//
//********************************************************

//#define LOCAL

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <vector>
#include <cstring>
#include <set>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

typedef long long LL;

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        while (!feof(stdin)) {
    #endif // LOCAL


    int a1, a2, a3;
    int b1, b2, b3;
    int n;
    scanf("%d %d %d", &a1, &a2, &a3);
    scanf("%d %d %d", &b1, &b2, &b3);
    scanf("%d", &n);
    int a = a1 + a2 + a3;
    int b = b1 + b2 + b3;

    if ((a+4) / 5 + (b+9) / 10 > n)
        printf("NO\n");
    else
        printf("YES\n");



    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
