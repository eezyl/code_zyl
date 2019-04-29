//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/1151/E
//   Date    :   2019/04/26
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

LL take_k (LL l, LL r, LL k) {
    LL n = r-l+1;
    LL total = n*(n+1)/2;
    LL l_range = k-l;
    LL l_total = l_range*(l_range+1)/2;
    LL r_range = r-k;
    LL r_total = r_range*(r_range+1)/2;
    return total-l_total-r_total;
}

//#define LOCAL
const LL LL_INF = 1 << 61;
int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        while (!feof(stdin)) {
    #endif // LOCAL

    int n;
    scanf("%d", &n);
    vector<LL> a(n);
    for (int i = 0; i < n; ++i)
        scanf("%I64d", &a[i]);
    LL ans = take_k(1, n, a[0]);
    for (int i = 1; i < n; ++i) if (a[i] != a[i-1]) {
        if (a[i-1] > a[i])
            ans += take_k(1, a[i-1]-1, a[i]);
        else
            ans += take_k(a[i-1]+1, n, a[i]);
    }

    cout << ans << endl;

    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
