//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1195/B
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

    LL n, k;
    scanf("%I64d %I64d", &n, &k);
    LL root = (-3 + sqrt(9+8*(n+k)))/2;
    printf("%I64d\n", n-root);

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
