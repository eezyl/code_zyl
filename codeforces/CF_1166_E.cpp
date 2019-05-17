//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1166/E
//   Date    :   2019/05/17
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

    int m, n;
    scanf("%d %d", &m, &n);
    vector<LL> num(n+1, 0);
    LL bitMark = 1;
    bool ans_mark = true;
    for (int i = 0; i < m; i++) {
        int s;
        scanf("%d", &s);

        vector<int> visited(n+1, 0);
        LL flag = LL_INF;
        for (int j = 0; j < s; j++) {
            int k;
            scanf("%d", &k);
            visited[k] = 1;
            flag &= num[k];
        }
        if (flag != 0)
            ans_mark = false;
        for (int j = 1; j <= n; j++) {
            if (visited[j] == 0)
                num[j] |= bitMark;
        }
        bitMark <<= 1;
    }

    if (ans_mark)
        printf("possible\n");
    else
        printf("impossible\n");

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
