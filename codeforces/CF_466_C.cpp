//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/466/C
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

    int n;
    scanf("%d", &n);
    vector<LL> a(n+1);
    a[0] = 0;
    for (int i = 1; i <= n; i++)
        scanf("%I64d", &a[i]);

    LL zero_count = 0;
    vector<LL> pre_sum(n+1);
    pre_sum[0] = 0;

    for (int i = 1; i <= n; i++) {
        pre_sum[i] = pre_sum[i-1] + a[i];
        if (pre_sum[i] == 0)
            zero_count++;
    }

    LL total = pre_sum[n];
    if (total % 3 != 0 || n < 3)
        printf("0\n");
    else if (total == 0) {
        zero_count--;
        //LL ans = (LL)(zero_count-1)*zero_count/2;
        printf("%I64d\n", zero_count*(zero_count-1)/2);
    }
    else {
        LL d = total / 3;
        vector<int> acc(n+1);
        acc[n] = 0;
        LL ans = 0;
        for (int i = n-1; i > 0; i--) {
            if (pre_sum[i] == d)
                ans += acc[i+1];

            if (pre_sum[i] == 2*d)
                acc[i] = acc[i+1]+1;
            else
                acc[i] = acc[i+1];
        }
        printf("%I64d\n", ans);
    }


    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
