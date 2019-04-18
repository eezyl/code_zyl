//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/617/A
//   Date    :   2019/04/18 (upload date)
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


    int n;
    scanf("%d", &n);

    printf("%d\n", (n+4) / 5);

    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
