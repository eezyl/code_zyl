//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1196/C
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

    int t = 100000;
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int n;
        scanf("%d", &n);
        int maxx = -t;
        int minx = t;
        int maxy = -t;
        int miny = t;
        for (int j = 0; j < n; ++j) {
            int x, y, f1, f2, f3, f4;
            scanf("%d%d%d%d%d%d",&x, &y, &f1, &f2, &f3, &f4);
            if (f1 == 0)
                maxx = max(maxx, x);
            if (f2 == 0)
                miny = min(miny, y);
            if (f3 == 0)
                minx = min(minx, x);
            if (f4 == 0)
                maxy = max(maxy, y);
        }
        if (maxx > minx || maxy > miny)
            printf("0\n");
        else
            printf("1 %d %d\n", maxx, maxy);

    }

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
