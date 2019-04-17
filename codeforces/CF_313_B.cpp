//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/313/B
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

    char str[100005];
    scanf(" %s", str);
    int n = strlen(str);

    vector<int> v(n+1, 0);
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (str[i] == str[i-1])
            sum++;
        v[i] = sum;
    }

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", v[b-1] - v[a-1]);
    }

    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
