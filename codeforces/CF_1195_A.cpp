//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1195/A
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

    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> drink_counts(k+1, 0);
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        drink_counts[num]++;
    }
    int t = (n+1)/2;
    sort(drink_counts.rbegin(), drink_counts.rend());
    int ans = 0;
    for (int i = 0; i < k && t > 0; ++i) {
        int p = min(t, drink_counts[i]/2);
        ans += p*2;
        t -= p;
        drink_counts[i] %= 2;
    }
    printf("%d\n", ans+t);

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
