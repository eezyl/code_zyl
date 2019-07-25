//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1196/B
//   Date    :   2019/07/24
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

LL gcd (LL a, LL b) {
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

int main()
{
#ifdef LOCAL
freopen("data.in", "r", stdin);
while (!feof(stdin)) {
#endif // LOCAL

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int n, k;
        scanf("%d%d", &n, &k);
        vector<LL> a(n);
        int odd = 0;
        for (int j = 0; j < n; ++j) {
            scanf("%I64d", &a[j]);
            if (a[j]%2)
                ++odd;
        }
        if (odd >= k && (odd-k)%2==0) {
            printf("YES\n");
            int c = k-1;
            for (int j = 0; j < n && c != 0; ++j) {
                if (a[j]%2) {
                    printf("%d ", j+1);
                    --c;
                }
            }
            printf("%d\n", n);
        } else {
            printf("NO\n");
        }
    }

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
