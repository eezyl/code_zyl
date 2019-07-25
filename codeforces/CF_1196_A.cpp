//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1196/A
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

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        LL a, b, c;
        scanf("%I64d%I64d%I64d", &a, &b, &c);
        printf("%I64d\n",(a+b+c)/2);
    }

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
