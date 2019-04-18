//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/489/B
//   Date    :   2019/04/18 (upload date)
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
using namespace std;

typedef long long LL;

const int INF = 1 << 25;

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        //freopen("data.out", "w", stdout);
    #endif // LOCAL

    int n;
    int m;
    vector<int> a(105, 0);
    vector<int> b(105, 0);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        a[num]++;
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int num;
        scanf("%d", &num);
        b[num]++;
    }

    int ans = 0;
    for (int i = 1; i <= 100; i++) {
        for (int j = i-1; a[i] > 0 && j <= i+1; j++)
            if (b[j] > 0) {
                int num = std::min(a[i], b[j]);
                a[i] -= num;
                b[j] -= num;
                ans += num;
            }
    }

    printf("%d\n", ans);

    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
