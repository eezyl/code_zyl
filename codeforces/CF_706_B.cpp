//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/706/B
//   Date    :   2019/04/18 (upload date)
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
#include <unordered_map>
using namespace std;

typedef long long LL;

const int INF = 1 << 25;

//#define LOCAL

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        //freopen("data.out", "w", stdout);
    #endif // LOCAL

    int n;
    scanf("%d", &n);

    vector<int> x(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &x[i]);
    sort(x.begin(), x.end());

    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        int m;
        scanf("%d", &m);
        printf("%d\n", upper_bound(x.begin(), x.end(), m)-x.begin());
    }

    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
