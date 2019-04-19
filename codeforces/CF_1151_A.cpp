//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/1151/A
//   Date    :   2019/04/18
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

using namespace std;

typedef long long LL;

const int INF = 1 << 25;

//#define LOCAL

int dis(char a, char b) {
    int d = abs(a-b);
    d = min(d, 26-d);
    return d;
}

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        while (!feof(stdin)) {
    #endif // LOCAL

    string genome("ACTG");
    int n;
    scanf("%d\n", &n);
    string str;
    cin >> str;
    int ans = 100000;
    for (int i = 0; i < n-3; i++) {
        int d = 0;
        for (int j = 0; j < 4; j++)
            d += dis(str[i+j], genome[j]);
        if (ans > d)
            ans = d;
    }
    printf("%d\n", ans);
    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
