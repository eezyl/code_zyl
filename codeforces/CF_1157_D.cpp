//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/1157/D
//   Date    :   2019/04/29
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

const int INF = 1 << 30;
const LL LL_INF = 1 << 62;

LL my_pow(LL k) {
    if (k >= 31)
        return LL(1024*1024*1024);
    LL result = 1;
    for (int i = 0; i < k; i++)
        result *=2;
    return result-1;
}

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        while (!feof(stdin)) {
    #endif // LOCAL

    LL n, k;
    scanf("%I64d %I64d", &n, &k);
    LL lower_b = k*(k+1)/2;
    LL upper_b = my_pow(k);
    // cout << lower_b << " " << upper_b << endl;
    if (lower_b > n) {
        printf("NO\n");
        return 0;
    }
    /*
    if (k == 1) {
        printf("YES\n");
        printf("%I64d\n", n);
        return 0;
    }
    */
    LL diff = n - lower_b;
    LL mul = diff / k;
    lower_b += k*mul;
    upper_b *= (mul+1);
    if (n > upper_b) {
        printf("NO\n");
        return 0;
    }
    vector<LL> ans(k);
    ans[0] = 1+mul;
    for (int i = 1; i < k; i++) {
        ans[i] = ans[i-1] + 1;
    }

    diff = n - lower_b;
    for (int i = k-1; i >= 1 && diff > 0; i--) {
        if (2*ans[i-1]-ans[i] >= diff) {
            ans[i] += diff;
            break;
        }
        ans[i-1]++;
        diff--;
        if (2*ans[i-1]-ans[i] >= diff) {
            ans[i] += diff;
            break;
        }
        diff -= 2*ans[i-1]-ans[i];
        ans[i] = ans[i-1]*2;
    }
    printf("YES\n");
    for (int i = 0; i < k; i++)
        printf("%I64d ", ans[i]);
    printf("\n");
    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
