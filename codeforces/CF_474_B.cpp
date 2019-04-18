//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/474/B
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
using namespace std;

typedef long long LL;

const int INF = 1 << 25;

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        //freopen("data.out", "w", stdout);
    #endif // LOCAL

    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    vector<int> acc(n+1);
    acc[0] = 0;
    for (int i = 1; i <= n; i++) {
        acc[i] = acc[i-1] + a[i-1];
    }

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int num;
        scanf("%d", &num);
        printf("%d\n", lower_bound(acc.begin(), acc.end(), num)-acc.begin());
    }

    //printf("%d\n", ans);

    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
