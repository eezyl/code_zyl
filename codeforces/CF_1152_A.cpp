//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/1152/A
//   Date    :   2019/04/24
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
const LL LL_INF = 1 << 61;
int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        while (!feof(stdin)) {
    #endif // LOCAL

    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> a(n);
    vector<int> b(m);
    int chest_even = 0, chest_odd = 0;
    int key_even = 0, key_odd = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i]&1)
            chest_odd++;
        else
            chest_even++;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
        if (b[i]&1)
            key_odd++;
        else
            key_even++;
    }

    int x = min(chest_even, key_odd);
    int y = min(chest_odd, key_even);
    int ans = x+y;
    printf("%d\n", ans);

    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
