//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/1150/A
//   Date    :   2019/04/29
//
//********************************************************

//#define LOCAL
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
const LL LL_INF = 1 << 61;

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        while (!feof(stdin)) {
    #endif // LOCAL

    int n, m, r;
    scanf("%d %d %d", &n, &m, &r);
    vector<int> a(n);
    vector<int> b(m);

    int min_v = 10001;
    int max_v = -1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] < min_v)
            min_v = a[i];
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
        if (b[i] > max_v)
            max_v = b[i];
    }
    if (min_v >= max_v)
        printf("%d\n", r);
    else
        printf("%d\n", r/min_v*max_v+r%min_v);



    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
