//********************************************************
//
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces
//   Address :   https://codeforces.com/problemset/problem/339/B
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



int main()
{
    #ifdef LOCAL
        freopen("data.in", "r", stdin);
    #endif // LOCAL


    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(m+1, 1);
    for (int i = 1; i <= m; i++)
        scanf("%d", &a[i]);

    LL ans = 0;
    for (int i = 1; i <= m; i++)
        ans += (a[i]-a[i-1]+n) % n;

    printf("%I64d\n", ans);

    #ifdef LOCAL
        printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
    #endif // LOCAL
    return 0;
}
