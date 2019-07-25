//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1174/B
//   Date    :   2019/06/03
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

int main()
{
#ifdef LOCAL
freopen("data.in", "r", stdin);
while (!feof(stdin)) {
#endif // LOCAL

    int n;
    scanf("%d", &n);
    vector<int> num(n);
    int odd = 0;
    int even = 0;

    for (int i = 0; i < n; ++i) {
        scanf("%d", &num[i]);
        if (num[i] & 1) {
            ++odd;
        } else {
            ++even;
        }
    }
    if (odd == 0 || even == 0) {
        for (int i = 0; i < n; ++i)
            printf("%d ", num[i]);
        printf("\n");
    } else {
        sort(num.begin(), num.end());
        for (int i = 0; i < n; ++i)
            printf("%d ", num[i]);
        printf("\n");
    }


#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
