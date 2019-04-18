//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/124/A
//   Date    :   2019/04/17 (upload date)
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

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        //freopen("data.out", "w", stdout);
    #endif // LOCAL


    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i-1 >= a && n-i <=b)
            ans++;
    }
    printf("%d\n", ans);

    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
