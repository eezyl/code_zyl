// =====================================================
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1395/A
//   Date    :   2020/08/12
// =====================================================

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
#include <unordered_map>
using namespace std;
typedef long long LL;

const int INF = (1<<31)-1;
const LL LL_INF = (1ll << 63)-1;
const int MOD = 1e9+7;

LL gcd (LL a, LL b) {
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
freopen("data.in", "r", stdin);
while (!feof(stdin)) {
#endif // LOCAL

    int t;
    cin >> t;
    while (t--) {
        vector<LL> num(4);
        cin >> num[0] >> num[1] >> num[2] >> num[3];
        sort(num.begin(), num.begin() + 3);
        LL odd = 0;
        for (int i = 0; i < 4; ++i)
            if (num[i]%2)
                ++odd;
        if (odd <= 1) {
            printf("YES\n");
            continue;
        }
        if (num[0] == 0) {
            printf("NO\n");
            continue;
        }
        odd = 0;
        for (int i = 0; i < 4; ++i) {
            ++num[i];
            if (num[i]%2)
                ++odd;
        }
        if (odd <= 1) {
            printf("YES\n");
        } else
            printf("NO\n");
    }

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
