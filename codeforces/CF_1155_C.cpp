//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/1155/C
//   Date    :   2019/04/22
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

//#define LOCAL

LL gcd (LL m, LL n) {
    if (n == 0)
        return m;
    return gcd(n, m%n);
}

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        while (!feof(stdin)) {
    #endif // LOCAL

    int n, m;
    scanf("%d %d", &n, &m);
    vector<LL> x(n);
    vector<LL> p(m);
    for (int i = 0; i < n; i++)
        scanf("%I64d", &x[i]);
    for (int i = 0; i < m; i++)
        scanf("%I64d", &p[i]);
    LL min_div = x[1] - x[0];
    for (int i = 1; i < n && min_div!= 1; i++)
        if ((x[i]-x[i-1]) % min_div != 0)
            min_div = gcd(min_div, x[i]-x[i-1]);
    //cout << min_div << endl;
    for (int i = 0; i < m; i++) {
        if (min_div % p[i] == 0) {
            printf("YES\n");
            printf("%I64d %d", x[0], i+1);
            return 0;
        }
    }
    printf("NO\n");

    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
