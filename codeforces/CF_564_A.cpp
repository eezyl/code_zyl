//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/564/A
//   Date    :   2019/04/23 (upload date)
//
//********************************************************

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

typedef long long int LL;

int main()
{
    LL k, n ,w;
    scanf("%I64d%I64d%I64d", &k, &n, &w);
    LL ans = -1 * n;

    LL num = k * (w*(w+1) / 2);
    ans += num;

    if (ans <= 0)
        printf("0\n");
    else
        printf("%I64d\n", ans);
    return 0;
}
