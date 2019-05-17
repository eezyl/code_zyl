//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1166/C
//   Date    :   2019/05/17
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

    int n;
    scanf("%d", &n);
    vector<LL> num(n);
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &num[i]);
        num[i] = abs(num[i]);
    }
    sort(num.begin(), num.end());
    LL ans = 0;
    for (auto it = num.begin(); it != num.end(); it++) {
        auto it2 = upper_bound(it, num.end(), (*it) * 2);
        LL diff = it2-it-1;
        if (diff > 0)
            ans+=diff;
    }
    printf("%I64d\n", ans);

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
