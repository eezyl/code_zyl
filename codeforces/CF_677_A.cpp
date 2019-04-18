//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/667/A
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

using namespace std;

typedef long long LL;



int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
    #endif // LOCAL


    int n, h;
    scanf("%d %d", &n, &h);
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int p;
        scanf("%d", &p);
        if (p > h)
            ans++;
        ans++;
    }

    printf("%d\n", ans);




    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
