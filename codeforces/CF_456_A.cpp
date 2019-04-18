//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/456/A
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
    vector<pair<int, int> > laptop(n);

    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        laptop[i] = make_pair(a, b);
    }

    sort(laptop.begin(), laptop.end());

    int cur_a = laptop[0].first;
    int cur_b = laptop[0].second;

    for(int i = 1; i < n; i++) {
        int a = laptop[i].first;
        int b = laptop[i].second;

        if (a > cur_a && b < cur_b) {
            printf("Happy Alex\n");
            return 0;
        }

        if (b > cur_b) {
            cur_a = a;
            cur_b = b;
        }
    }

    printf("Poor Alex\n");


    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
