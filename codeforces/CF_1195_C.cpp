//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1195/C
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
    scanf("%d", &n);
    vector<LL> v1(n), v2(n);
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", &v1[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", &v2[i]);
    }

    vector<LL> chooseA(n+1, 0), chooseB(n+1, 0), noChoose(n+1, 0);
    chooseA[0] = v1[0];
    chooseB[0] = v2[0];
    for (int i = 1; i < n; ++i) {
        chooseA[i] = v1[i] + max(chooseB[i-1], noChoose[i-1]);
        chooseB[i] = v2[i] + max(chooseA[i-1], noChoose[i-1]);
        noChoose[i] = max(chooseA[i-1], chooseB[i-1]);
    }
    LL ans = chooseA[n-1];
    if (chooseB[n-1] > ans)
        ans = chooseB[n-1];
    if (noChoose[n-1] > ans)
        ans = noChoose[n-1];
    printf("%I64d\n", ans);

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
