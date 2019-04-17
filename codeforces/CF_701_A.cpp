//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/701/A
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
#include <unordered_map>
using namespace std;

typedef long long LL;

const int INF = 1 << 25;

//#define LOCAL

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        while (!feof(stdin)) {
    #endif // LOCAL

    int n;
    scanf("%d", &n);
    vector<int> a(n+1);
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    int target = sum * 2 / n;
    vector<bool> locked(n+1, false);
    for (int i = 1; i <= n; i++) {
        if (locked[i])
            continue;

        for (int j = i+1; j <= n; j++) {
            if (locked[j])
                continue;
            if (a[i]+a[j] == target) {
                locked[i] = true;
                locked[j] = true;
                printf("%d %d\n", i, j);
                break;
            }
        }
    }

    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
