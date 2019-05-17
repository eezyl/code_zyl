//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1167/D
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

    int n;
    scanf("%d", &n);
    string str;
    cin >> str;
    vector<int> ans(n, -1);
    int f = 0;
    int g = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == '(') {
            ans[i] = f;
            f = !f;
        }
        if (str[i] == ')') {
            ans[i] = g;
            g = !g;
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d", ans[i]);
    printf("\n");

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}