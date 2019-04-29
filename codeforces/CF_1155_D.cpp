//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/1155/D
//   Date    :   2019/04/24
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


using namespace std;

typedef long long LL;

const int INF = 1 << 25;

//#define LOCAL
const LL LL_INF = 1 << 61;
int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        while (!feof(stdin)) {
    #endif // LOCAL

    int n;
    LL x;
    LL ans = 0;
    scanf("%d %I64d", &n, &x);
    vector<LL> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &a[i]);
    }
    vector<LL> dp1(n+1);
    dp1[0] = a[0];
    ans = max(ans, dp1[0]);
    for (int i = 1; i < n; i++) {
        dp1[i] = std::max(dp1[i-1], 0LL) + a[i];
        ans = max(ans, dp1[i]);
    }
    vector<LL> dp2(n+1);
    dp2[0] = a[0] * x;
    ans = max(ans, dp2[0]);
    for (int i = 1; i < n; i++) {
        dp2[i] = max(max(dp1[i-1], dp2[i-1]), 0LL) + a[i] * x;
        ans = max(ans, dp2[i]);
    }
    vector<LL> dp3(n+1);
    dp3[1] = a[0] * x + a[1];
    ans = max(ans, dp3[1]);
    for (int i = 2; i < n; i++) {
        dp3[i] = std::max(dp2[i-1], dp3[i-1]) + a[i];
        ans = max(ans, dp3[i]);
    }
    printf("%I64d\n", ans);

    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
