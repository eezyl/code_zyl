//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1165/E
//   Date    :   2019/05/14
//
//********************************************************

//#define LOCAL
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long LL;

const int INF = (1<<31)-1;
const LL LL_INF = (1ll << 63)-1;

int main()
{
#ifdef LOCAL
freopen("data.in", "r", stdin);
while (!feof(stdin)) {
#endif // LOCAL

    LL n;
    LL mod = 998244353LL;
    scanf("%I64d", &n);
    vector<LL> a(n);
    vector<LL> b(n);
    for (int i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%I64d", &b[i]);

    for (LL i = 0; i < n; i++) {
        a[i] = a[i] * (i+1) * (n-i);
    }
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        a[i] %= mod;
        b[i] %= mod;
        ans += (a[i] * b[i])%mod;
        ans %= mod;
    }
    printf("%I64d\n", ans);

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
