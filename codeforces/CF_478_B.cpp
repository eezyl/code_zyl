//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/478/B
//   Date    :   2019/04/18 (upload date)
//
//********************************************************

#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <vector>
#include <cstring>
#include <set>
#include <string>
#include <algorithm>
#include <map>
#include <iostream>
#include <cmath>
#include <stack>
#include <bitset>
#include <unordered_map>
using namespace std;

typedef long long LL;

const int INF = 1 << 25;

//#define LOCAL

LL CombNto2(LL n)
{
    return (n*(n-1))/2;
}

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        //freopen("data.out", "w", stdout);
    #endif // LOCAL

    LL m, n;
    scanf("%I64d %I64d", &n, &m);
    LL ans_min, ans_max;

    LL t = n - (m-1);
    ans_max = CombNto2(t);

    LL d = n/m;
    LL r = n%m;
    ans_min = r * CombNto2(d+1) + (m-r) * CombNto2(d);

    printf("%I64d %I64d\n", ans_min, ans_max);

    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
