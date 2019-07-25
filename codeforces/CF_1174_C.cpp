//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1174/C
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
    vector<int> ans(n+1, 0);
    for (int i = 2; i <= n; i+=2)
        ans[i] = 1;
    int color = 2;
    int k = 3;
    while (k <= n) {
        if (ans[k] == 0) {
            for (int i = k; i <= n; i+=k)
                ans[i] = color;
            ++color;
        }
        k += 2;
    }
    for (int i = 2; i <= n; i++)
        printf("%d ", ans[i]);
    printf("\n");


#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
