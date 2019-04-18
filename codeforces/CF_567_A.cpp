//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/567/A
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
    vector<int> x(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    //sort(x.begin(), x.end());
    for (int i = 0; i < n; i++) {
        if (i == 0)
            printf("%d %d\n", x[1]-x[0], x[n-1]-x[0]);
        else if (i == n-1)
            printf("%d %d\n", x[n-1]-x[n-2], x[n-1]-x[0]);
        else
            printf("%d %d\n", std::min(x[i]-x[i-1], x[i+1]-x[i]), std::max(x[i]-x[0], x[n-1]-x[i]));
    }


    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
