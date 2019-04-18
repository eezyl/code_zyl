//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/119/A
//   Date    :   2019/04/17 (upload date)
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

using namespace std;

typedef long long LL;

int gcd(int a, int b)
{
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;
    return gcd (b, a % b);
}

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
    #endif // LOCAL

    int a, b, n;
    scanf("%d %d %d", &a, &b, &n);
    int count = 1;
    while (n)
    {
        if (count)
        {
            int take = gcd(a, n);

            n -= take;
        }
        else
        {
            int take = gcd(b, n);

            n -= take;
        }
        count = !count;
    }
    printf("%d\n", count);

    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
