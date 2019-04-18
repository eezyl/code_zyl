//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/749/A
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
#include <unordered_map>
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

    int ans = 0;
    int has3 = 0;
    if (n%2) {
        has3 = 1;
        n -= 3;
    }

    ans += n/2;

    if (has3) {
        printf("%d\n", ans+1);
        printf("3 ");
        for (int i = 0; i < ans; i++)
            printf("2 ");
        printf("\n");
    } else {
        printf("%d\n", ans);
        for (int i = 0; i < ans; i++)
            printf("2 ");
        printf("\n");
    }

    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
