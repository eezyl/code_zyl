//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1165/A
//   Date    :   2019/05/14
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

    int n, x, y;
    scanf("%d %d %d", &n, &x, &y);
    vector<int> digit(n);
    for (int i = 0; i < n; i++)
        scanf(" %1d", &digit[i]);
    reverse(digit.begin(), digit.end());
    int ans = 0;
    if (digit[y] == 0)
        ans++;
    for (int i = 0; i < x; i++) if (i != y)
        if (digit[i] == 1)
            ans++;
    printf("%d\n", ans);


#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
