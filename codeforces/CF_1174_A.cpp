//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1174/A
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
    vector<int> num(2*n);
    set<int> m;
    for (int i = 0; i < n*2; ++i) {
        int a;
        scanf("%d", &a);
        num[i] = a;
        m.insert(a);
    }
    if (m.size() == 1)
        printf("-1\n");
    else {
        sort(num.begin(), num.end());
        for (int i = 0; i < 2*n; ++i) {
            printf("%d ", num[i]);
        }
        printf("\n");
    }

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
