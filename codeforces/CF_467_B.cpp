//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/467/B
//   Date    :   2019/04/18 (upload date)
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

bool isFriend(int t, int k)
{
    int ans = 0;
    for (int i = 1; i != 0; i <<= 1) {
        if (t & i)
            ans++;
    }
    return ans <= k;
}

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        //freopen("data.out", "w", stdout);
    #endif // LOCAL

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int ans = 0;
    vector<int> v(m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &v[i]);
    }

    int num;
    scanf("%d", &num);
    for (int i = 0; i < m; i++) {
        int temp = num ^ v[i];
        ans += isFriend(temp, k);
    }

    printf("%d\n", ans);

    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
