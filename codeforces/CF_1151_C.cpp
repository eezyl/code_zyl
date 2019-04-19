//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/1151/C
//   Date    :   2019/04/18
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

LL m = 1000000007;

LL mul_mod(LL a, LL b) {
    a %= m;
    b %= m;
    return (a*b%m);
}

LL f(LL k) {
    LL ini_num = 1;
    LL ini_sum = 1;
    LL ans = 0;
    int flag = true;
    for (LL i = 1; i && k>0; i <<= 1) {
        if (k >= i) {
            k -= i;
            ans = (ans+ini_sum) % m;
        } else {
            ans = (((ans + mul_mod(k, k))%m + mul_mod(ini_num, k))%m - k)%m;
            break;
        }

        if (flag) {
            ini_num = (2*ini_num) % m;
            ini_sum = ((4*ini_sum) % m + (i*2) % m ) % m;
        } else {
            ini_num = (2*ini_num-1) % m;
            ini_sum = (4*ini_sum) % m;
        }
        flag = !flag;
        // cout << ini_num << " " << ini_sum << endl;
    }
    // cout << ans << endl;
    return ans;
}

LL pos_mod(LL k) {
    k %= m;
    if (k < 0)
        k += m;
    return k;
}


int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        while (!feof(stdin)) {
    #endif // LOCAL

    LL a, b;
    scanf("%I64d %I64d", &a, &b);

    printf("%I64d\n", pos_mod((f(b)-f(a-1))));

    #ifdef LOCAL
        }
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
