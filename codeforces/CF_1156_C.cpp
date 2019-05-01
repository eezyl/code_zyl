//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/1156/C
//   Date    :   2019/05/01
//
//********************************************************

//#define LOCAL
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
const LL LL_INF = 1ll << 61;

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        while (!feof(stdin)) {
    #endif // LOCAL

    int n, z;
    scanf("%d %d", &n, &z);
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int ans = 0;
    sort(a.begin(), a.end());

    int b = 0;
    int c = n/2;
    while (b < n/2 && c < n) {
        if (a[c]-a[b] >= z) {
            b++;
            ans++;
        }
        c++;
    }

    printf("%d\n", ans);


    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
