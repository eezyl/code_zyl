//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/716/A
//   Date    :   2019/04/18 (upload date)
//
//********************************************************

//#define LOCAL

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
using namespace std;

typedef long long LL;

const int INF = 1 << 25;



int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        //freopen("data.out", "w", stdout);
    #endif // LOCAL

    int n, c;
    scanf("%d %d", &n, &c);

    int ans = 1;
    int prev, curr;
    scanf("%d", &curr);
    prev = curr;
    for (int i = 1; i < n; i++) {
        scanf("%d", &curr);
        if (curr - prev <= c)
            ans++;
        else
            ans = 1;
        prev = curr;
    }

    printf("%d\n", ans);

    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
