//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/237/A
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
        freopen("datain.txt", "r", stdin);
        //freopen("data.out", "w", stdout);
    #endif // LOCAL

    int n;
    scanf("%d", &n);
    int ans = 0;
    map<pair<int, int>, int> time;
    for (int i = 0; i < n; i++) {
        int h, m;
        scanf("%d %d", &h, &m);
        pair<int, int> p = make_pair(h, m);
        auto it = time.find(p);
        if (it == time.end())
            time[p] = 1;
        else
            time[p]++;
        if (time[p] > ans)
            ans = time[p];
    }
    printf("%d\n", ans);

    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
