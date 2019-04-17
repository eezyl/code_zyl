//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/318/A
//   Date    :   2019/04/17 (upload date)
//
//********************************************************

// #define LOCAL

#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <vector>

using namespace std;

typedef long long LL;

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
    #endif // LOCAL


    LL n, k;
    scanf("%I64d%I64d", &n, &k);
    LL q = (n+1) / 2;

    if (k <= q)
        printf("%I64d\n", 2*k-1);
    else
        printf("%I64d\n", 2*(k - q));

    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
