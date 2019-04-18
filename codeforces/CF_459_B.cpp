//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/459/B
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
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    sort(b.begin(), b.end());

    int min_b = b[0];
    int acc_min = 1;
    int max_b = min_b;
    int acc_max = 1;

    for (int i = 1; i < n; i++) {
        if (b[i] == min_b)
            acc_min++;
        if (b[i] > max_b) {
            max_b = b[i];
            acc_max = 1;
        } else if (b[i] == max_b)
            acc_max++;
    }

    if (max_b == min_b)
        printf("0 %I64d\n", (LL)n*(n-1)/2);
    else
        printf("%d %I64d\n", max_b-min_b, (LL)acc_max*acc_min);

    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
