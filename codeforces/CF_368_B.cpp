//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/368/B
//   Date    :   2019/04/17 (upload date)
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
        FILE* fin =
        freopen("data.in", "r", stdin);
        //freopen("data.out", "w", stdout);
    #endif // LOCAL

    int n, m;
    scanf("%d %d", &n, &m);
    unordered_map<int, int> ma;
    vector<int> ans(n);
    vector<int> num(n);
    int dif = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);

        auto it = ma.find(num[i]);
        if (it == ma.end()) {
            ma[num[i]] = 1;
            dif++;
        }
        else
            ma[num[i]]++;
    }

    for (int i = 0; i < n; i++) {
        ans[i] = dif;
        ma[num[i]]--;
        if (ma[num[i]] == 0)
            dif--;
    }

    for (int i = 0; i < m; i++) {
        int b;
        scanf("%d", &b);
        printf("%d\n", ans[b-1]);
    }

    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
