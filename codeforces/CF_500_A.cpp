//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/500/A
//   Date    :   2019/04/18 (upload date)
//
//********************************************************

//#define LOCAL

#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <vector>
#include <cstring>

using namespace std;

typedef long long LL;

int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
    #endif // LOCAL


    int n, t;
    scanf("%d %d", &n, &t);
    vector<int> a(n+10, 0);
    vector<bool> b(n+10, 0);
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int step = 1;
    while (step < n)
    {
        step += a[step];
        b[step] = 1;
    }
    if (b[t] == true)
        printf("YES\n");
    else
        printf("NO\n");

    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
