//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1195/D1
//   Date    :   2019/07/17
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

    int n;
    LL MOD = 998244353;
    vector<LL> ten_exp;
    ten_exp.push_back(1);
    for (int i = 1; i < 30; ++i) {
        LL a = (ten_exp[i-1] * 10) % MOD;
        ten_exp.push_back(a);
    }
    scanf("%d", &n);
    vector<string> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    LL ans = 0;
    int len = v[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < len; ++j) {
            LL digit = v[i][j] - '0';
            digit = digit*n % MOD;
            for (int k = 0; k < 2; ++k) {
                LL e = (len-j-1)*2+k;
                ans = (ans + (digit * ten_exp[e]) % MOD) % MOD;
            }
        }
    }
    printf("%I64d\n", ans);

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
