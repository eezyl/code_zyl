//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/731/A
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
        FILE* fin =
        freopen("datain.txt", "r", stdin);
        //freopen("data.out", "w", stdout);
    #endif // LOCAL

    char str[105];
    scanf("%s", str);
    int ans = 0;
    char prev_ch = 'a';
    char curr_ch = prev_ch;
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        curr_ch = str[i];
        int diff = abs(curr_ch - prev_ch);
        if (diff > 13)
            ans += (26-diff);
        else
            ans += diff;
        prev_ch = curr_ch;
    }

    printf("%d\n", ans);

    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
