//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces template
//   Address :   https://codeforces.com/problemset/problem/1167/C
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

void disjoint(vector<int>& p, int a, int b) {
    if (p[a] != a)
        disjoint(p, p[a], b);
    p[a] = b;
}

int addsize(vector<int>& p, vector<int>& s, int a) {
    if (p[a] == a) {
        s[a] += 1;
        return a;
    }
    if (p[a] != a) {
        int r = addsize(p, s, p[a]);
        p[a] = r;
        return r;
    }
}

int main()
{
#ifdef LOCAL
freopen("data.in", "r", stdin);
while (!feof(stdin)) {
#endif // LOCAL

    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> p(n+1, -1);
    vector<int> s(n+1, 0);
    for (int i = 0; i < m; i++) {
        int k;
        scanf("%d", &k);
        if (k == 0)
            continue;
        vector<int> num(k);
        for (int j = 0; j < k; j++)
            scanf("%d", &num[j]);
        for (int j = 0; j < k; j++) {
            if (p[num[j]] != -1)
                disjoint(p, p[num[j]], num[0]);
            p[num[j]] = num[0];
        }
    }
    for (int i = 1; i <= n; i++) if (p[i] != -1)
        addsize(p, s, i);
    for (int i = 1; i <= n; i++) {
        if (p[i] == -1)
            printf("1 ");
        else
            printf("%d ", s[p[i]]);
    }
    printf("\n");

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
