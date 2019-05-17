//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1167/A
//   Date    :   2019/05/15
//
//********************************************************

//#define LOCAL
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long LL;

const int INF = (1<<31)-1;
const LL LL_INF = (1ll << 63)-1;

int main()
{
#ifdef LOCAL
freopen("data.in", "r", stdin);
while (!feof(stdin)) {
#endif // LOCAL

    int t;
    scanf("%d", &t);
    for (int tt = 0; tt < t; ++tt) {
        int n;
        scanf("%d", &n);
        string str;
        cin >> str;
        if (n < 11) {
            printf("NO\n");
            continue;
        }
        int num = n - 11;
        bool flag = false;
        for (int i = 0; i <= num; ++i) {
            if (str[i] == '8') {
                flag = true;
                break;
            }
        }
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
