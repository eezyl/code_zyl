//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/1152/C
//   Date    :   2019/04/25
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

LL gcd(LL a, LL b) {
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

LL lcm (LL a, LL b) {
    return a/gcd(a,b) * b;
}

//#define LOCAL
const LL LL_INF = 1 << 62;
int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        while (!feof(stdin)) {
    #endif // LOCAL

    LL a, b;
    scanf("%I64d %I64d", &a, &b);
    if (a > b)
        swap(a, b);
    /*
    if (b % a == 0 || a+1 == b) {
        printf("0\n");
        return 0;
    }
    */

    LL min_lcm = lcm(a, b);
    LL best_k = 0;

    LL diff = b - a;
    LL sq = sqrt(diff);
    for (LL i = 1; i <= sq; i++) {
        if (diff % i == 0) {
            LL k = i - a%i;
            LL cur_lcm = lcm(a+k, b+k);
            if (min_lcm > cur_lcm) {
                min_lcm = cur_lcm;
                best_k = k;
            } else if (min_lcm == cur_lcm) {
                best_k = min(best_k, k);
            }
            LL div = diff/i;
            k = div - a%div;
            cur_lcm = lcm(a+k, b+k);
            if (min_lcm > cur_lcm) {
                min_lcm = cur_lcm;
                best_k = k;
            } else if (min_lcm == cur_lcm) {
                best_k = min(best_k, k);
            }
        }
    }

    printf("%I64d\n", best_k);

    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
